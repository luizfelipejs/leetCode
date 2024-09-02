#include <stdlib.h> 

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {

    while (head != NULL && head->val == val) {
        struct ListNode* elementToRemove = head;
        head = head->next;
        free(elementToRemove);
    }
    struct ListNode* currentElement = head; 

    while (currentElement != NULL && currentElement->next != NULL) { 
        if (currentElement->next->val == val) { 
            struct ListNode* elementToRemove = currentElement->next; 
            currentElement->next = currentElement->next->next; 
            free(elementToRemove); 
        } else {
            currentElement = currentElement->next; 
        }
    }

    return head; 
}