#include "caesar.h"

int main(int argc, char **argv) {

    char* str = "AAA aaa";
    char* str1 = "ZZZ zzz";

    for (size_t i = 0; i < 26; i++)
        printf("%llu - %s\n", i, caesarCipher_decrypt(str, i));

    for (size_t i = 0; i < 26; i++)
        printf("%llu - %s\n", i, caesarCipher_encrypt(str1, i));

    return EXIT_SUCCESS;
}
