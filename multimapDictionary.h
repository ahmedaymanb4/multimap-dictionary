#ifndef MULTIMAPDICTIONARY_H_INCLUDED
#define MULTIMAPDICTIONARY_H_INCLUDED

typedef struct node{
    char *key;
    int value;
    struct node *next;
}Node;

Node *createNode(char *key, int value);
void addPair(Node **head, char *key, int value);
void removePair(Node **head, char *key);
void modifyValue(Node *head, char *key, int newValue);
void printValuesForKey(Node *head, char *key);
void freeList(Node *head);

#endif // MULTIMAPDICTIONARY_H_INCLUDED
