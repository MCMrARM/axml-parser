cmake_minimum_required(VERSION 3.11)
project(axml_parser)

set(CMAKE_CXX_STANDARD 11)

set(AXML_LIB_SRC include/axml/axml_file.h include/axml/endian_aware_int.h lib/axml_file.cpp include/axml/chunk_header.h include/axml/string_pool.h lib/string_pool.cpp include/axml/chunk_header_range.h lib/chunk_header_range.cpp include/axml/axml_parser.h lib/axml_parser.cpp include/axml/chunk_xml.h)
include_directories(include)
add_executable(axml_parser main.cpp ${AXML_LIB_SRC})