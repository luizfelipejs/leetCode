#include <stdlib.h> 

struct ListNode
{
    int val;
    struct ListNode *next;
};
/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
*/


struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* currentElementOnLinkedList = head;
    int sizeOfLinkedList = 0;

    while (currentElementOnLinkedList != NULL) { 
        currentElementOnLinkedList = currentElementOnLinkedList->next;
        sizeOfLinkedList++; 
    }

    int index = 0;
    int middleOfLinkedlist = sizeOfLinkedList / 2; 
    currentElementOnLinkedList = head; 

    while (index < middleOfLinkedlist) { 
        currentElementOnLinkedList = currentElementOnLinkedList->next; 
        index++; 
    }

    return currentElementOnLinkedList;
}