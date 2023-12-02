// --- Day 1: Trebuchet?! ---
// Kosa Matyas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBERS_COUNT 10

char numbers[NUMBERS_COUNT][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int extractDigits(char *line, int *first, int *second) {
    *first = -1;
    *second = -1;

    for (int i = 0; i < strlen(line); i++) {
        if (isdigit(line[i])) {
            if (*first == -1) {
                *first = line[i] - '0';
                *second = line[i] - '0';
            } else {
                *second = line[i] - '0';
            }
        } else {
            for (int j = 0; j < NUMBERS_COUNT; j++) {
                if (strstr(&line[i], numbers[j]) == &line[i]) {
                    if (*first == -1) {
                        *first = *second = j;
                    } else {
                        *second = j;
                    }
                }
            }
        }
    }

    return (*first * 10) + *second;
}

int processFile(const char *filename) {
    FILE *input = fopen(filename, "r");

    char *line = NULL;
    size_t line_length = 0;
    int total = 0;

    while (getline(&line, &line_length, input) != -1) {
        int first, second;
        total += extractDigits(line, &first, &second);
    }

    free(line);
    fclose(input);

    return total;
}

int main() {
    const char *filename = "input.txt";
    int total = processFile(filename);
    printf("Total: %d\n", total);

    return 0;
}
