#pragma once

#include "axml_file.h"
#include "chunk_xml.h"

namespace axml {

class AXMLParser {

public:
    enum EventType {
        START_NAMESPACE, END_NAMESPACE,
        START_ELEMENT, END_ELEMENT
    };

private:
    template <typename T>
    void checkNode(ChunkHeader* header) {
        if (header->headerSize < sizeof(XMLNodeChunkHeader))
            throw std::runtime_error("Header is too small");
        if (header->size - header->headerSize < sizeof(T))
            throw std::runtime_error("Not enough chunk data");
    }

    template <typename T>
    T* getNode() const {
        ChunkHeader* header = rangeIt;
        return (T*) ((size_t) header + header->headerSize);
    }

    ChunkHeaderRange& range;
    StringPool& stringPool;
    ChunkHeaderRange::Iterator rangeIt;
    bool firstEl = true;

    EventType evType;

    void incrementIterator();

public:
    AXMLParser(ChunkHeaderRange& range, StringPool& stringPool) : range(range), stringPool(stringPool),
                                                                  rangeIt(range.begin()) {
    }
    AXMLParser(AXMLFile& file) : AXMLParser(file.getDocumentRange(), file.getStringPool()) {}

    bool next();

    EventType eventType() const { return evType; }

    std::string getNamespacePrefix() const { return stringPool.getString(getNode<NamespaceChunkData>()->prefix); }
    std::string getNamespaceUrl() const { return stringPool.getString(getNode<NamespaceChunkData>()->url); }



};

}