#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <axml/axml_file.h>

int main(int argc, const char* argv[]) {
    const char* path = argv[1];
    int fd = open(path, O_RDONLY);
    auto size = lseek64(fd, 0, SEEK_END);
    lseek64(fd, 0, SEEK_SET);
    if (size < 0)
        throw std::runtime_error("Failed to get file size");
    void* ptr = mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
    axml::AXMLFile file (ptr, size);
    munmap(ptr, size);
    return 0;
}