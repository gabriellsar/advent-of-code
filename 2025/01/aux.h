typedef struct DLinkedList
{
    struct DLinkedList* prev;
    struct DLinkedList* next;
    int data;

} DLinkedList;

DLinkedList* createNode(int data);
DLinkedList* insertAtBeginning(DLinkedList* head, int data);
DLinkedList* createClock(DLinkedList* head, int qtd);
DLinkedList* searchNode(DLinkedList* head, int data);
void printList(DLinkedList* head);