#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int createBF(char* filename);

int getBFchar(char* benWord);

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
        int id = getBFchar(buffer);
        if (id != -1) {
            fprintf(benFile, "%s ", BEN_WORDS[id]);
        }
    }
    fclose(brainFile);
    fclose(benFile);
    return 1;
}

int getBFchar(char* benWord) {
    char BRAIN_WORDS [8][2] = {">", "<", "+", "-", "[", "]", ",", "."};
    for (int i = 0; i < 8; i++) {
        if (strcmp(benWord, BRAIN_WORDS[i]) == 0) {
            return i;
        }
    }
    return -1;
}