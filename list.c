// In the list.c file

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createList(List *ps) {
    ps->head = NULL;
}

int ListEmpty(List *ps) {
    return ps->head == NULL;
}

void createNode(Node**node) {
    *node = (Node *)malloc(sizeof(Node));
    if (*node) {
        (*node)->next = NULL;
        (*node)->list = NULL; // Initialize sublist to NULL
    }
}

int insertNode(List *ps, int key, char value[]) {
    Node* newNode;
    createNode(&newNode);
    if (newNode == NULL) {
        return 0; // Memory allocation failed
    }
    newNode->key = key;
    strcpy(newNode->value, value);
    createList(&(newNode->list)); // Initialize sublist for the new node

    if (ListEmpty(ps) || key < ps->head->key) {
        newNode->next = ps->head;
        ps->head = newNode;
    } else {
        Node *current = ps->head;
        Node *prev = NULL;
        while (current && current->key < key) {
            prev = current;
            current = current->next;
        }
        if (current && current->key == key) {
            free(newNode);
            return 0; // Key already exists
        }
        prev->next = newNode;
        newNode->next = current;
    }
    return 1; // Insertion successful
}

int removeKey(List *ps, int key) {
    if (ListEmpty(ps)) {
        return 0; // List is empty
    }
    Node *current = ps->head;
    Node *prev = NULL;
    int removed = 0;
    while (current) {
        if (current->key == key) {
            removed = 1;
            if (prev == NULL) {
                ps->head = current->next;
                free(current->list); // Free sublist memory
                free(current);
                current = ps->head;
            } else {
                prev->next = current->next;
                free(current->list); // Free sublist memory
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    return removed;
}

int modifyValue(List *ps, int key, char newValue[]) {
    Node *current = ps->head;
    while (current) {
        if (current->key == key) {
            strcpy(current->value, newValue);
            return 1; // Modification successful
        }
        current = current->next;
    }
    return 0; // Key not found
}

int printValuesForKey(List *ps, int key) {
    Node *current = ps->head;
    int found = 0;
    while (current != NULL) {
        if (current->key == key) {
            found = 1;
            Node *subcurrent = current->list; // Traverse the sublist
            while (subcurrent != NULL) {
                printf("%d: %s\n", subcurrent->key, subcurrent->value);
                subcurrent = subcurrent->next;
            }
            break; // No need to continue searching
        }
        current = current->next;
    }
    return found;
}
