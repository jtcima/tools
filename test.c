#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char* addLetter(char* string, char *c) {
    char* result = malloc(sizeof(string) + 2);
    strcpy(result, string);
    strncat(result, c, 1);
    return result;
}

char* removeLetter(char* string, char *c) {
    char* result = malloc(sizeof(string));
    int j = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != *c) {
            result[j++] = string[i];
        }
    }
    result[j] = '\0';

    return result;
}

void makeAnagram(char *anagram, char *letters) {

    if (*letters == '\0') {
        printf("%s\n", anagram);
        return;
    }

    char *c = letters;
    while (*c != '\0') {
        makeAnagram(addLetter(anagram, c),
                    removeLetter(letters, c));
        c++;
    }

}

int main() {

    makeAnagram("", "1234");

    return 0;
}
