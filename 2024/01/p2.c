#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 1000

int main() {

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char buffer[MAX_LINE_LENGTH];
    int right_column[MAX_LINES];
    int left_column[MAX_LINES];

    int index = 0;

    char *token;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        token = strtok(buffer, " ");
        right_column[index] = atoi(token);
                
        while (token != NULL) {
            token = strtok(NULL, " ");
        
            if (token != NULL) {
                left_column[index] = atoi(token);
            }
        }

        index++;
    }
    fclose(file);

    
    int diff = 0;
    for (int i = 0; i < MAX_LINES; i++) {
        int qtd = 0;

        for (int j = 0; j < MAX_LINES; j++) {
            if (right_column[i] == left_column[j]) {
                qtd++;
            }
        }
        
        diff += right_column[i] * qtd;
        qtd = 0;
    }
    
    printf("%d\n", diff);

    return 0;
}