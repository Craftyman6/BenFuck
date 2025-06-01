#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "benfuck.h"

int createBF(char* filename);

int getBFchar(char* benWord);

int createBF(char* filename) {

    char BRAIN_WORDS [8][2] = {">", "<", "+", "-", "[", "]", ",", "."};

    FILE* benFile;
    if ((benFile = fopen(filename, "r")) == NULL) {
        printf("Could not read BenFuck file");
        return 0;
    }

    FILE* brainFile;
    brainFile = fopen("brainfuck.bf", "w");

    char* buffer = malloc(sizeof(char) * 100);

    while (fscanf(benFile, "%s", buffer) == 1) {
        int id = getBFchar(buffer);
        if (id != -1) {
            fprintf(brainFile, "%s", BRAIN_WORDS[id]);
        }
    }
    fclose(benFile);
    fclose(brainFile);
    return 1;
}

int getBFchar(char* benWord) {
    char BEN_WORDS[8][7] = {"ben", "hohoho", "yes", "no", "*ring", "*burp", "grrr", "ugh"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(benWord, BEN_WORDS[i]) == 0) {
            return i;
        }
    }
    return -1;
}