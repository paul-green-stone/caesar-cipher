#include "caesar.h"

char* caesarCipher_encrypt(char* const plaintext, size_t key) {
    char* ciphertext = NULL;

    if (plaintext == NULL)
        return ciphertext;

    if (key == 0)
        return plaintext;

    key %= 26;

    if ((ciphertext = (char*) malloc(sizeof(char) * strlen(plaintext) + 1)) != NULL) {
        for (size_t i = 0; plaintext[i] != '\0'; i++) {
            if ((plaintext[i] >= 65) && (plaintext[i] <= 90)) {
                ciphertext[i] = ((plaintext[i] + key) > 90) ? 65 + (plaintext[i] + key - (90 + 1)) : plaintext[i] + key;
            }
            else if ((plaintext[i] >= 97) && (plaintext[i] <= 122)) {
                ciphertext[i] = ((plaintext[i] + key) > 122) ? 97 + (plaintext[i] + key - (122 + 1)) : plaintext[i] + key;
            }
            else
                // Left unchanged
                ciphertext[i] = plaintext[i];
        }
        ciphertext[strlen(plaintext) + 1] = '\0';
    }

    return ciphertext;
}

char* caesarCipher_decrypt(char* const ciphertext, size_t key) {
    char* plaintext = NULL;

    if (ciphertext == NULL)
        return plaintext;

    if (key == 0)
        return ciphertext;

    key %= 26;

    if ((plaintext = (char*) malloc(sizeof(char) * strlen(ciphertext) + 1)) != NULL) {
        for (size_t i = 0; ciphertext[i] != '\0'; i++) {
            if ((ciphertext[i] >= 65) && (ciphertext[i] <= 90))
                plaintext[i] = ((ciphertext[i] - key) < 65) ? 90 - 65 + (ciphertext[i] - key + 1) : ciphertext[i] - key;
            else if ((ciphertext[i] >= 97) && (ciphertext[i] <= 122))
                plaintext[i] = ((ciphertext[i] - key) < 97) ? 122 - 97 + (ciphertext[i] - key + 1) : ciphertext[i] - key;
            else
                plaintext[i] = ciphertext[i];
        }
        plaintext[strlen(ciphertext) + 1] = '\0';
    }

    return plaintext;
}
