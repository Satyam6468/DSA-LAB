#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void addAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Add node at end
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Add node after a given key
void addAfterKey(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from beginning.\n");
}

// Delete node at end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from end.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from end.\n");
}

// Delete node by key
void deleteByKey(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node with key %d deleted.\n", key);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Key %d not found.\n", key);
        return;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Node with key %d deleted.\n", key);
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    int choice, data, key;
    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Add after Key\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete by Key\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addAtEnd(&head, data);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                addAfterKey(head, key, data);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(&head, key);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
