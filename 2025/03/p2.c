#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 256
#define DIGIT_COUNT 12

void findmax(char* curr, char* buffer, const size_t bufferlen, size_t index, int ndigit) {
    if (ndigit > DIGIT_COUNT) {
        return;
    }
    
    int max = 0;
    int digitsleft = (DIGIT_COUNT - ndigit);
    for (int i = index; i < bufferlen - digitsleft; i++) {
        if (buffer[i] - '0' > max) {
            max = buffer[i] - '0';
            index = i;
        }
    }
    curr[ndigit - 1] = buffer[index];
    findmax(curr,buffer,bufferlen,index + 1,ndigit + 1);
}

int main() {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    __uint64_t resp = 0;

    char buffer[BUFFER_SIZE];

    char currmax[DIGIT_COUNT + 1];
    currmax[DIGIT_COUNT] = '\0';

    while (fgets(buffer, sizeof(buffer), file) != NULL) {        
        buffer[strcspn(buffer, "\n")] = '\0';
        size_t bufferlen = strlen(buffer);
        
        findmax(currmax,buffer,bufferlen,0,1);
        resp += strtoull(currmax, NULL, 10);
    }

    printf("%llu\n", resp);
    fclose(file);
    return 0;
}