#ifndef MULTIMAP_DICTIONARY_H_INCLUDED
#define MULTIMAP_DICTIONARY_H_INCLUDED

typedef struct node {  // Node structure
    char *key;
    int value;
    struct Node *next;
} Node;

//  Functions Prototypes:
Node *createNode(char *key, int value);
void addPair(Node **head, char *key, int value);  // Function to add a key-value pair to the linked list
void removePair(Node **head, char *key);  // Function to remove a key-value pair from the linked list
void modifyValue(Node *head, char *key, int newValue);  // Function to modify the value of an existing pair
void printValuesForKey(Node *head, char *key);  // Function to print values associated with a particular key
void freeList(Node *head);  // Function to free memory allocated for the linked list

#endif // MULTIMAP_DICTIONARY_H_INCLUDED
