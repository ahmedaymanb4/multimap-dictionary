#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multimap dictionary.h"

int main() {
    Node *head = NULL;

    // Example usage
    addPair(&head, "apple", 10);
    addPair(&head, "banana", 20);
    addPair(&head, "orange", 30);

    printValuesForKey(head, "banana");

    modifyValue(head, "banana", 25);
    printValuesForKey(head, "banana");

    removePair(&head, "banana");
    printValuesForKey(head, "banana");

    freeList(head);

    return 0;
}
