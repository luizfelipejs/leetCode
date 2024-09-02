#include <stdlib.h> 

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *currentElementA = headA;
    struct ListNode *currentElementB = headB;

    while (currentElementA != currentElementB)
    {
        currentElementA = (currentElementA == NULL) ? headB : currentElementA->next;
        currentElementB = (currentElementB == NULL) ? headA : currentElementB->next;
    }

    return currentElementA;
}