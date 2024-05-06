#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multimapDictionary.h"


Node *createNode(char *key, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        exit(1);  // A special case, if memory allocation failed.
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


// Function to add a key-value pair to the linked list
void addPair(Node **head, char *key, int value) {
    // to create the new node.
    // It's as if createNode(char *key, int value) is called,
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        exit(1);  // A special case, checks if memory allocation failed.
    newNode->key = strdup(key);
    if (!newNode->key)
        exit(1);  // A special case, checks if the allocation of memory for string within the node was successful.
    newNode->value = value;
    newNode->next = NULL;
    // A special case. Checks if the linked list is empty,
    // or if newNode's key < key of the first node in the list
    if (*head == NULL || strcmp(key, (*head)->key) < 0) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        Node *current = *head;
        while ((current->next) && (strcmp(key, current->next->key) > 0))
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}


// Function to remove a key-value pair from the linked list
void removePair(Node **head, char *key) {
    Node *current = *head;
    Node *prev = NULL;

    while ((current) && (strcmp(current->key, key) != 0)) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->key);
    free(current);
}


// Function to modify the value of an existing pair
void modifyValue(Node *head, char *key, int newValue) {
    Node *current = head;
    while ((current) && (strcmp(current->key, key) != 0))
        current = current->next;
    if (!current)
        printf("Key not found.\n");
    else {
        current->value = newValue;
    }
}


// Function to print values associated with a particular key
void printValuesForKey(Node *head, char *key) {
    Node *current = head;
    while (current != NULL && strcmp(current->key, key) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Key not found.\n");
    } else {
        printf("Values associated with key %s: %d\n", key, current->value);
    }
}


// Function to free memory allocated for the linked list
void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp->key);
        free(temp);
    }
}

