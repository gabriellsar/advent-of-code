#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int resp = 0;

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        
        buffer[strcspn(buffer, "\n")] = '\0';
        size_t bufferlen = strlen(buffer) - 1;

        int maxs = -1;
        int maxe;
        
        for (size_t i = 0; i < bufferlen; i++) {
            if (maxs < buffer[i] - '0') {

                maxs = buffer[i] - '0';                 
                maxe = buffer[i + 1] - '0';
                
                for (size_t j = i + 1; j < bufferlen + 1; j++) {
                    maxe = (maxe < buffer[j] - '0') ? buffer[j] - '0' : maxe;
                }
            }            
        }
        
        resp += 10*maxs + maxe;

    }
    printf("%d\n", resp);
    fclose(file);
    return 0;
}