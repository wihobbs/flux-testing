// A really simple locked memory test
// Run with argument 1 as the number of kb of memory
// you want to lock like:
//     ./memory_lock 65
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

#define KILOBYTES 1024

int main (int argc, char **argv)
{
    // Number of kilobytes is the first argument
    assert (argc == 2);
    int kb = atoi (argv[1]);

    // Allocate the memory and check that the pointer is not null (malloc succeeded)
    int *ptr = (int *)malloc (kb * KILOBYTES);
    if (!(ptr)) {
        fprintf (stderr, "malloc: %s\n", strerror (errno));
        exit (EXIT_FAILURE);
    }
    printf ("Allocated %d", kb);
    printf ("kb at address %p\n", ((void *)ptr));

    // Lock the memory and store the return code from doing so,
    // then use that as the function return code
    if (mlock (ptr, (kb * KILOBYTES)) < 0) {
        fprintf(stderr, "mlock: %s\n", strerror (errno));
        exit (EXIT_FAILURE);
    }
    printf ("Locked %d kb successfully\n", kb);
    return 0;
}
