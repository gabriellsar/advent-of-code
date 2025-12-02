#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

DLinkedList* createNode(int data) {
    DLinkedList* node = (DLinkedList*)malloc(sizeof(DLinkedList));

    node->data = data;
    node->next = node->prev = NULL;
    return node; 
}

DLinkedList* insertAtBeginning(DLinkedList* head, int data) {
    DLinkedList* newNode = createNode(data);
    if (!head) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    }
    else {
        DLinkedList* last = head->prev; 

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        
        head = newNode;
    }
    return head;
}

DLinkedList* createClock(DLinkedList* head, int qtd) {
    head->next = createNode(qtd - 1);
    head->next->prev = head;
    head->next->next = createNode(qtd);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->prev = head->next->next;
    
    for (int i = 3; i <= qtd; i++) {
        head = insertAtBeginning(head, qtd - i);
    }
    return head;
}

DLinkedList* searchNode(DLinkedList* head, int data) {
    DLinkedList* curr = head;
    do {
        if (curr->data == data) {
            return curr; // Node found
        }
        curr = curr->next;
    } while (curr != head);
    return NULL; // Node not found
}


void printList(DLinkedList* head) {
    if (!head) return;
    DLinkedList* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}