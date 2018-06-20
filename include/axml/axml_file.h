#pragma once

#include <istream>
#include <vector>
#include "endian_aware_int.h"
#include "string_pool.h"
#include "chunk_header_range.h"

namespace axml {

class AXMLFile {

private:
    void* data;
    size_t size;

    StringPool stringPool;

public:
    AXMLFile(void* data, size_t size) : data(data), size(size) {
        ChunkHeaderRange((ChunkHeader*) data, (ChunkHeader*) ((size_t) data + size)).validate();
    }

    StringPool& getStringPool() { return stringPool; }

};

}