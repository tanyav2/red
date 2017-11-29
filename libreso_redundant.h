#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * Stores a file that has the path "file_path" at different locations
 * "num" number of times. "buf" refers to the contents of the file,
 * "buf_len" is the length of the buffer.
 *
 * Returns EXIT_SUCCESS = 0 on success; else EXIT_FAILURE = 1
 */

int storeRedundantly(char* file_path, char* buf, uint32_t buf_len, uint32_t num);
