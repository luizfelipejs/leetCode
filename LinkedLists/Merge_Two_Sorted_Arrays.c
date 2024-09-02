#include <stdlib.h> 
#include <stdio.h> 


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insertNodeOnTop(struct ListNode *list, int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->next = list;
    newNode->val = val;
    return newNode;
}
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *newList = NULL;
    struct ListNode *reverseList = NULL;

    if (list1 == NULL && list2 != NULL)
    {
        return list2;
    }
    else if (list2 == NULL && list1 != NULL)
    {
        return list1;
    }

    while (list1 != NULL && list2 != NULL)
    {
        if (list2->val == list1->val)
        {
            newList = insertNodeOnTop(newList, list1->val);
            newList = insertNodeOnTop(newList, list2->val);
            list1 = list1->next;
            list2 = list2->next;
        }
        else if (list1->val < list2->val)
        {
            newList = insertNodeOnTop(newList, list1->val);
            list1 = list1->next;
        }
        else if (list2->val < list1->val)
        {
            newList = insertNodeOnTop(newList, list2->val);
            list2 = list2->next;
        }
    }

    while (list1 != NULL)
    {
        newList = insertNodeOnTop(newList, list1->val);
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        newList = insertNodeOnTop(newList, list2->val);
        list2 = list2->next;
    }

    // inverter Lista encadeada
    while (newList != NULL)
    {
        reverseList = insertNodeOnTop(reverseList, newList->val);
        newList = newList->next;
    }

    return reverseList;
}