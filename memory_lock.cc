// A really simple locked memory test
// Run with argument 1 as the number of kb of memory
// you want to lock like:
//     ./memory_lock 65
//

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <ostream>
#include <cassert>
#include <sys/mman.h>

#define KILOBYTES 1024

int main(int argc, char* argv[]) {
    // Number of kilobytes is the first argument
    assert(argc == 2);
    int kb = atoi(argv[1]);
    
    // Allocate the memory and check that the pointer is not null (malloc succeeded)
    int* ptr = (int*) malloc(kb*KILOBYTES);
    if (!ptr) {
        return -1
    }
    std::cout << "Allocated " << kb << "kb at address " << ptr << std::endl;

    // Lock the memory and store the return code from doing so, 
    // then use that as the function return code
    int return_code = mlock(ptr, (kb*KILOBYTES));
    std::cout << "Locking of " << kb << "kb returned error code " << return_code << std::endl;
    return return_code;
}
