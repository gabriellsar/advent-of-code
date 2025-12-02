#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

#define MAX_LINE_LENGTH 256

int main() {
    FILE *fp;
    char buffer[MAX_LINE_LENGTH];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int qtd = 99;
    DLinkedList* head = createNode(qtd - 2);
    head = createClock(head, qtd);

    DLinkedList* curr = searchNode(head, 50);

    int sum = 0;
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        char letter = buffer[0];
        int number = atoi(&buffer[1]);

        for (int i = 0; i < number; i++) {
            // Handle left rotation
            if (letter == 'L') {
                curr = curr->prev;
                if (curr->data == 0) {
                    sum++;
                }
            }
            // Handle right rotation
            else {
                curr = curr->next;
                if (curr->data == 0) {
                    sum++;
                }
            }
        }
    }
    printf("Sum: %d\n", sum);
    fclose(fp);
    return 0;
}