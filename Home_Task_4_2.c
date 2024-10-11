#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int find_substring(const char* original, const char* substring) {
    int original_len = strlen(original);
    int substring_len = strlen(substring);

    if (substring_len > original_len) {
        return -1;
    }

    for (int i = 0; i <= original_len - substring_len; i++) {
        int match = 1;
        for (int j = 0; j < substring_len; j++) {
            if (original[i + j] != substring[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return i;
        }
    }

    return -1;
}

int main() {
    char original[100], substring[100];

    printf("Enter original string: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = '\0'; 
    printf("Enter substring: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; 

    to_lowercase(original);
    to_lowercase(substring);

    int result = find_substring(original, substring);

    if (result != -1) {
        printf("Substring found at index: %d\n", result);
    } else {
        printf("Substring found at index: -1\n");
    }

    return 0;
}
