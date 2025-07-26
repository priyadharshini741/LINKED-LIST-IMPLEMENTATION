#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// File pointer
FILE *fp;

// Insert node at end
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Inserted: %d\n", data);
    fprintf(fp, "Inserted: %d\n", data);
}

// Delete node by value
void delete(int key) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted: %d\n", key);
        fprintf(fp, "Deleted: %d\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found: %d\n", key);
        fprintf(fp, "Value not found: %d\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted: %d\n", key);
    fprintf(fp, "Deleted: %d\n", key);
}

// Traverse the list
void traverse() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Linked List is empty.\n");
        fprintf(fp, "Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");
    fprintf(fp, "Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        fprintf(fp, "%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    fprintf(fp, "NULL\n");
}

// Main function
int main() {
    int choice, value;

    // Open file for writing
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    do {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Traverse Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting program.\n");
                fprintf(fp, "Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select 1-4.\n");
                fprintf(fp, "Invalid choice.\n");
        }

    } while (choice != 4);

    fclose(fp); // Close
    return 0;
}