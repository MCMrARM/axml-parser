#pragma once

#include <cstddef>
#include "endian_aware_int.h"

namespace axml {

struct ChunkHeader {
    enum {
        TYPE_STRING_POOL = 1,
        TYPE_XML = 3
    };

    euint16 type;
    euint16 headerSize;
    euint32 size;
};

}