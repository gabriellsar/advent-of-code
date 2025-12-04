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

    long resp = 0;

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        
        buffer[strcspn(buffer, "\n")] = '\0';
        size_t bufferlen = strlen(buffer) - 1;

        int maxs = 0, maxe = 0;
        size_t maxsindex = 0;

        for (int i = 0; i < bufferlen; i++) {
            if (buffer[i] - '0' > maxs) {
                maxs = buffer[i] - '0';
                maxsindex = i + 1;
            }
        }

        for (int j = maxsindex; j < bufferlen + 1; j++) {
            if (buffer[j] - '0' > maxe) {
                maxe = buffer[j] - '0';
            }
        }

        resp += 10*maxs + maxe;

    }
    printf("%d\n", resp);
    fclose(file);
    return 0;
}