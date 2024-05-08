#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define max 100

typedef struct node {
    int key;
    char value[max];
    struct node* list; // Pointer to the list associated with this node
    struct node* next;
} Node;
typedef struct {
    Node* head;
} List;

void createList(List *ps);
int ListEmpty(List *ps);
int ListFull(List *ps);
void createNode(Node **node);
int insertNode(List *ps, int key, char value[]);
int removeKey(List*ps, int key);
int modifyValue(List *ps, int key, char newValue[]);
int printValuesForKey(List *ps, int key);

#endif // LIST_H_INCLUDED
