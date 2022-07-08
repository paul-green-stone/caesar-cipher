#include "caesar.h"

char* caesarCipher_encrypt(char* const plaintext, size_t key) {
    char* ciphertext = NULL;
    key = key % 26;

    if ((plaintext != NULL) && (strlen(plaintext) != 0)) {
        if ((ciphertext = (char*) malloc(sizeof(char) * strlen(plaintext) + 1)) != NULL) {
            for (size_t i = 0; *(plaintext + i) != '\0'; i++) {
                // For upper case letters
                if ((*(plaintext + i) >= 'A') && (*(plaintext + i) <= 'Z'))
                    *(ciphertext + i) = (*(plaintext + i) + key > 'Z') ? 'A' + (*(plaintext + i) + key - 'A') % 26 : *(plaintext + i) + key;

                //For lower case letters
                else if ((*(plaintext + i) >= 'a') && (*(plaintext + i) <= 'z'))
                    *(ciphertext + i) = (*(plaintext + i) + key > 'z') ? 'a' + (*(plaintext + i) + key - 'a') % 26 : *(plaintext + i) + key;

                // For other characters
                else
                    *(ciphertext + i) = *(plaintext + i);
            }

            *(ciphertext + strlen(ciphertext)) = '\0';
        }
    }

    return ciphertext;
}

char* caesarCipher_decrypt(char* const ciphertext, size_t key) {
    char* plaintext = NULL;
    key = key % ('z' - 'a');

    if ((ciphertext != NULL) && (strlen(ciphertext) != 0)) {
        if ((plaintext = (char*) malloc(sizeof(char) * strlen(ciphertext) + 1)) != NULL) {
            for (size_t i = 0; *(ciphertext + i) != '\0'; i++) {
                // For upper case letters
                if ((*(ciphertext + i) >= 'A') && (*(ciphertext + i) <= 'Z'))
                    *(plaintext + i) = (*(ciphertext + i) - key < 'A') ? 1 + 'Z' - ('A' - (*(ciphertext + i) - key)) % 26 : *(ciphertext + i) - key;

                // For lower case letters
                else if ((*(ciphertext + i) >= 'a') && (*(ciphertext + i) <= 'z'))
                    *(plaintext + i) = (*(ciphertext + i) - key < 'a') ? 1 + 'z' - ('a' - (*(ciphertext + i) - key)) % 26 : *(ciphertext + i) - key;

                // For other characters
                else
                    *(plaintext + i) = *(ciphertext + i);
            }

            *(plaintext + strlen(plaintext)) = '\0';
        }
    }

    return plaintext;
}
