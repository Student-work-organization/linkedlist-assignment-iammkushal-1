#include <stdio.h>
#include <stdlib.h>

struct CircularNode {
    int data;
    struct CircularNode* next;
};

struct CircularLinkedList {
    struct CircularNode* head;
};

struct CircularNode* createNode(int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_at_end(struct CircularLinkedList* list, int data) {
    struct CircularNode* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
        return;
    }

    struct CircularNode* temp = list->head;

    while (temp->next != list->head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = list->head;
}

void delete_node(struct CircularLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode *curr = list->head, *prev = NULL;

    if (curr->data == data) {
        if (curr->next == list->head) {
            free(curr);
            list->head = NULL;
            return;
        }

        while (curr->next != list->head) {
            curr = curr->next;
        }

        struct CircularNode* temp = list->head;
        curr->next = temp->next;
        list->head = temp->next;
        free(temp);
        return;
    }

    prev = list->head;
    curr = list->head->next;

    while (curr != list->head) {
        if (curr->data == data) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Value not found\n");
}

void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct CircularNode* temp = list->head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);

    printf("(head)\n");
}

int main() {
    struct CircularLinkedList list;
    list.head = NULL;

    insert_at_end(&list, 10);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);

    printf("List after insertion:\n");
    display(&list);

    delete_node(&list, 20);

    printf("List after deletion:\n");
    display(&list);

    return 0;
}