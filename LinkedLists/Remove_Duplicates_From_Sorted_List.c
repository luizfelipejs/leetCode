#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *currentElement = head;
    while (currentElement != NULL && currentElement->next != NULL)
    {
        if (currentElement->val == currentElement->next->val)
        {
            struct ListNode *duplicated = currentElement->next;

            currentElement->next = duplicated->next;
            free(duplicated);
        }
        else
        {
            currentElement = currentElement->next;
        }
    }

    return head;
}