#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h> 

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}