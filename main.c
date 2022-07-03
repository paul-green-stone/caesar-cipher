#include "caesar.h"

int main(int argc, char **argv) {

    char *plaintext = "My name is Ilya.";
    char* ciphertext = NULL;
    size_t key = 10;

    char* decrypted_message = NULL;

    if ((ciphertext = caesarCipher_encrypt(plaintext, 10)) != NULL)
        printf("%s (%llu) %s\n", plaintext, key, ciphertext);

    if ((decrypted_message = caesarCipher_decrypt(ciphertext, key)) != NULL)
        printf("%s (%llu) %s\n", ciphertext, key, decrypted_message);

    return EXIT_SUCCESS;
}
