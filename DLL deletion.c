#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

struct DoublyNode* head = NULL;

void insert_at_end(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    struct DoublyNode* temp = head;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void delete_node(int data) {
    struct DoublyNode* temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void delete_the_end_node() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct DoublyNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void delete_node_with_givenData(int data) {
    delete_node(data);
}

void traverse_backward() {
    struct DoublyNode* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);

    delete_node(20);
    delete_the_end_node();
    delete_node_with_givenData(10);

    traverse_backward();

    return 0;
}