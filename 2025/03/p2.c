#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 256
#define MAX_SIZE 12

void find_max_sequence(const char* buffer,const size_t buffer_size,size_t size_left,char* maxs, size_t index) {
    if (size_left + index == MAX_SIZE) {
        strcpy(maxs, buffer);
        return;
    }

    char max = buffer[index]; 
    size_t max_index = 0;

    for (size_t i = index; i < buffer_size - size_left; i++) {
        if (buffer[i] > max) {
            max = buffer[i];
            max_index = i;
        }
    }
    printf("Max found %c at index %zu\n", max, max_index);
    maxs[MAX_SIZE - size_left] = max;
    find_max_sequence(buffer, buffer_size, size_left - 1, maxs, max_index + 1);
}


int main() {
    FILE *file = fopen("sample-input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    unsigned long resp = 0;

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {        
        buffer[strcspn(buffer, "\n")] = '\0';
        
        char number[MAX_SIZE];
        find_max_sequence(buffer,strlen(buffer),MAX_SIZE, number, 0);
        number[MAX_SIZE] = '\0';

        printf("Number %s\n", number);
        resp += atol(number);
    }    
    printf("%lu\n", resp);

    fclose(file);
    return 0;
}