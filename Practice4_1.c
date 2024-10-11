#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100
#define ALPHABET_SIZE 26

void caesar_encrypt(char* input, int key) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = 'a' + (input[i] - 'a' + key) % ALPHABET_SIZE;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = 'A' + (input[i] - 'A' + key) % ALPHABET_SIZE;
        }
    }
}

int break_caesar(char* input) {
    int frequency[ALPHABET_SIZE] = {0};
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            frequency[input[i] - 'a']++;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            frequency[input[i] - 'A']++;
        }
    }

    int max_frequency = 0;
    int max_index = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
            max_index = i;
        }
    }

    int key = (max_index - ('e' - 'a' + ALPHABET_SIZE) % ALPHABET_SIZE) % ALPHABET_SIZE;
    return key;
}

int main() {
    char input[MAX_INPUT];
    int key;

    printf("Enter a normal English string (up to 100 characters): ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; 
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    caesar_encrypt(input, key);

    printf("Encrypted string: %s\n", input);

    int broken_key = break_caesar(input);
    printf("Broken encryption key: %d\n", broken_key);

    return 0;
}