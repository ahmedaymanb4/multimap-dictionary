#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "multimapDictionary.h"

int main() {
    Node *head = NULL;

    // Example usage
    addPair(&head, "Ahmed", 10);
    addPair(&head, "Ahmed", 99);
    addPair(&head, "Omar", 20);
    addPair(&head, "Hassan", 30);

    printValuesForKey(head, "Ahmed");

    modifyValue(head, "Ahmed", 25);
    printValuesForKey(head, "Ahmed");

    removePair(&head, "Ahmed");
    printValuesForKey(head, "Ahmed");

    freeList(head);

    return 0;
}
