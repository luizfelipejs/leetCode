#include <stdlib.h> 
#include <stdbool.h> 

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* insertNodeOnTop (struct ListNode* list, int val) { 
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode)); 
    newNode->val = val; 
    newNode->next = list;  
    return newNode; 
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* reversedList = NULL;
    struct ListNode* currentElement = head;  

    while (currentElement != NULL) { 
        reversedList = insertNodeOnTop(reversedList, currentElement->val); 
        currentElement = currentElement->next;  
    }

    return reversedList; 
}


bool isPalindrome(struct ListNode* head) {
    struct ListNode* reversedList = reverseList(head); 
    struct ListNode* currentElement = head; 

    while (currentElement != NULL) { 
        if (reversedList->val != currentElement->val) { 
            return false;
        }

        reversedList = reversedList->next; 
        currentElement = currentElement->next; 
    }

    return true; 
}