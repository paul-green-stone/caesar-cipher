#include "caesar.h"
#include <errno.h>
#include <getopt.h>

int main(int argc, char **argv) {

    // Global variables defined within the API:
    extern char* optarg;
    extern int optind, opterr, optopt;
    extern int errno;

    char* optstring = ":m:k:h";
    char* user_message = NULL;
    char* cipher = NULL;
    size_t key;

    // Parsing the command line arguments
    int opt;

    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'h':
                printf("usage: %s -m message/plaintext -k key\n", argv[0]);

                break ;
            case 'm':
                if ((user_message = (char*) malloc(sizeof(char) * strlen(optarg) + 1)) != NULL)
                    memcpy(user_message, optarg, strlen(optarg) + 1);

                break ;
            case 'k':
                key = (size_t) atoi(optarg);

                break ;
            case '?':
                printf("Unknown option: -%c\n", optopt);

                break ;
            case ':':
                printf("Missing argument for -%c\n", optopt);

                break ;
        }
    }

    if (user_message != NULL) {
        if ((cipher = caesarCipher_encrypt(user_message, key)) != NULL) {
            printf("%s\n", cipher);

            free(cipher);
        }
        else {
            fprintf(stderr, "Error encrypting a message: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
