#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void printMenu() {
    printf("\n---- Menu ----\n");
    printf("1. Insert a node with sublist\n");
    printf("2. Insert value into sublist\n");
    printf("3. Remove a node by key\n");
    printf("4. Modify value by key\n");
    printf("5. Print values for a given key\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    List list;
    createList(&list);

    int choice;
    char value[max];
    int key;

    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character left in input buffer

        switch (choice) {
            case 1: {
                Node *newNode;
                createNode(&newNode);
                printf("Enter key for the node: ");
                scanf("%d", &newNode->key);
                getchar(); // Consume newline character left in input buffer
                insertNode(&list, newNode->key, ""); // Insert node without value for this example
                printf("Node with key %d and sublist created.\n", newNode->key);
                break;
            }
            case 2: {
    printf("Enter key for the node: ");
    scanf("%d", &key);
    getchar(); // Consume newline character left in input buffer
    Node *current = list.head;
    while (current != NULL && current->key != key) {
        current = current->next;
    }
    if (current != NULL) {
        printf("Enter key to insert into the sublist: ");
        scanf("%d", &key);
        printf("Enter value to insert into the sublist: ");
        scanf("%s", value);
        insertNode(&(current->list), key, value); // Use current->sublist instead of current->list
    } else {
        printf("Node with key %d not found.\n", key);
    }
    break;
}
            case 3:
                printf("Enter key to remove: ");
                scanf("%d", &key);
                if (removeKey(&list, key))
                    printf("Node with key %d removed successfully.\n", key);
                else
                    printf("Node with key %d not found.\n", key);
                break;
            case 4:
                printf("Enter key to modify and new value: ");
                scanf("%d %s", &key, value);
                if (modifyValue(&list, key, value))
                    printf("Value modified successfully.\n");
                else
                    printf("Node with key %d not found.\n", key);
                break;
            case 5:
                printf("Enter key to print values: ");
                scanf("%d", &key);
                if (!printValuesForKey(&list, key))
                    printf("No values found for key %d.\n", key);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
    } while (choice != 6); // Continue the main menu loop until the user chooses to exit

    return 0;
}
