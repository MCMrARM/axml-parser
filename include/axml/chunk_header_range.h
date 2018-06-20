#pragma once

#include "chunk_header.h"

namespace axml {

class ChunkHeaderRange {

private:
    ChunkHeader *pBegin, *pEnd;

public:
    class Iterator {
    private:
        ChunkHeader* header;
    public:
        Iterator(ChunkHeader* header) : header(header) {}

        ChunkHeader* operator ->() { return header; }
        ChunkHeader* operator*() { return header; }
        operator ChunkHeader*() { return header; }

        Iterator& operator++() {
            header = (ChunkHeader*) ((size_t) header + header->size);
            return *this;
        }
    };

    ChunkHeaderRange(ChunkHeader* pBegin, ChunkHeader* pEnd) : pBegin(pBegin), pEnd(pEnd) {}

    Iterator begin() const { return pBegin; }

    Iterator end() const { return pEnd; }

    void validate();

};

}