#include <axml/axml_parser.h>

using namespace axml;

void AXMLParser::incrementIterator() {
    if (firstEl)
        firstEl = false;
    else if (rangeIt != range.end())
        ++rangeIt;
}

bool AXMLParser::next() {
    while (true) {
        incrementIterator();
        if (rangeIt == range.end())
            return false;

        ChunkHeader* header = rangeIt;
        if (header->type == ChunkHeader::TYPE_XML_START_NAMESPACE ||
                header->type == ChunkHeader::TYPE_XML_END_NAMESPACE) {
            checkNode<NamespaceChunkData>(header);
            evType = header->type == ChunkHeader::TYPE_XML_START_NAMESPACE
                     ? EventType::START_NAMESPACE : EventType::END_NAMESPACE;
            return true;
        }
    }
}