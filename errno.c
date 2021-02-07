#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char * error = NULL;
    char * endptr = NULL;
    long input_converted = 0;

    if (argc != 2) {
        printf("usage: %s <errno>\n", argv[0]);
        return -1;
    }

    input_converted = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        printf("[%s] Error: Could not parse \"%s\" as a number.\n", argv[0], argv[1]);
        return -2;
    }

    error = strerror((int)input_converted);

    if (!error) {
        printf("[%s] strerror() did not return a string for error number %s\n", argv[0], argv[1]);
        return -2;
    }

    printf("errno: %s\n", error);
    return 0;
}
