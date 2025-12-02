#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 1000

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

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

    int n = sizeof(right_column) / sizeof(right_column[0]); 

    qsort(right_column,n, sizeof(int), compare);
    qsort(left_column,n,sizeof(int), compare);
    
    int diff = 0;
    for (int i = 0; i < MAX_LINES; i++) {
        diff += abs(right_column[i] - left_column[i]);
    }
    
    printf("%d\n", diff);

    fclose(file);
    return 0;
}