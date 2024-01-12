#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning\n", value);
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end\n", value);
}

void insertAtIndex(struct Node** head, int value, int index) {
    if (index < 0) {
        printf("Invalid index\n");
        return;
    }
    if (index == 0) {
        insertAtBeginning(head, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = *head;

    for (int i = 0; i < index - 1; ++i) {
        if (temp == NULL) {
            printf("Invalid index\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at index %d\n", value, index);
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted the first node\n");
}

void deleteAtIndex(struct Node** head, int index) {
    if (index < 0 || *head == NULL) {
        printf("Invalid index or empty list. Cannot delete.\n");
        return;
    }
    if (index == 0) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;

    for (int i = 0; i < index - 1; ++i) {
        if (temp->next == NULL) {
            printf("Invalid index\n");
            return;
        }
        temp = temp->next;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Deleted node at index %d\n", index);
}

void display(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    
    insertAtEnd(&head, 65);
    insertAtEnd(&head, 15);
    
    display(head);
    
    insertAtIndex(&head, 20, 1);
    display(head);

    deleteAtIndex(&head, 2);
    display(head);

    return 0;
}
