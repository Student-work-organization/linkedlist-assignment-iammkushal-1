#include <stdio.h>
#include <stdlib.h>

struct CircularNode {
    int data;
    struct CircularNode* next;
};

struct CircularNode* head = NULL;

void insert_at_beginning(int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    struct CircularNode* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_beginning(20);
    insert_at_beginning(30);

    traverse();

    return 0;
}