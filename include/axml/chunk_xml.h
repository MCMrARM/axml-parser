#pragma once

#include "chunk_header.h"

namespace axml {

struct XMLNodeChunkHeader : public ChunkHeader {
    euint32 lineNumber;
    StringRef comment;
};


struct NamespaceChunkData {
    StringRef prefix;
    StringRef url;
};

}