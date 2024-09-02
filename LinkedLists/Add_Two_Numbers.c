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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode* list1Element = l1; 
  struct ListNode* list2Element = l2; 
  struct ListNode* solutionList = NULL; 
  
  int carryOut = 0; 
  int sumNodes = 0; 

  while (list1Element != NULL || list2Element != NULL) { 
    int n1 = (list1Element != NULL) ? list1Element->val : 0; 
    int n2 = (list2Element != NULL) ? list2Element->val : 0; 
    
    sumNodes = n1 + n2 + carryOut; 

    carryOut = sumNodes / 10; 
    solutionList = insertNodeOnTop(solutionList, sumNodes % 10); 

    list1Element = (list1Element != NULL) ? list1Element->next : NULL; 
    list2Element = (list2Element != NULL) ? list2Element->next : NULL;  
  }

  if (carryOut > 0 && (list1Element == NULL && list2Element == NULL)) { 
    solutionList = insertNodeOnTop(solutionList, carryOut); 
  }

  return reverseList(solutionList); 
}