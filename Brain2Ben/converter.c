#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Given a BrainFuck character, returns id of associated BenFuck word
int getBFword(char* brainChar);

int main(int argc, const char * argv[]) {

    char BEN_WORDS[8][7] = {"ben", "hohoho", "yes", "no", "*ring", "*burp", "grrr", "ugh"};

    FILE* brainFile;
    if ((brainFile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Usage: %s nameOfBrainFuckFile\n", argv[0]);
        return 0;
    }

    FILE* benFile;
    benFile = fopen("benfuck.ben", "w");

    char* buffer = malloc(sizeof(char) * 100);

    while (fscanf(brainFile, "%c", buffer) == 1) {
        int id = getBFword(buffer);
        if (id != -1) {
            fprintf(benFile, "%s ", BEN_WORDS[id]);
        }
    }
    fclose(brainFile);
    fclose(benFile);
    return 1;
}

// Given a BrainFuck character, returns id of associated BenFuck word
int getBFword(char* brainChar) {
    char BRAIN_WORDS [8][2] = {">", "<", "+", "-", "[", "]", ",", "."};
    for (int i = 0; i < 8; i++) {
        if (strcmp(brainChar, BRAIN_WORDS[i]) == 0) {
            return i;
        }
    }
    return -1;
}