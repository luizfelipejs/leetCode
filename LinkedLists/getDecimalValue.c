#include <math.h> 
#include <stdlib.h> 

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

int getDecimalValue(struct ListNode* head) {
   struct ListNode* currentElement = reverseList(head); 
   int i = 0; 
   int sum = 0; 

   while (currentElement != NULL) { 
    sum += pow(2, i) * currentElement->val; 
    currentElement = currentElement->next; 
    i++; 
   }

   return sum; 
}