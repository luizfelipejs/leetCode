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

  while (list1Element != NULL && list2Element != NULL) { 
    sumNodes = list1Element->val + list2Element->val + carryOut; 

    if(sumNodes < 10) { 
        solutionList = insertNodeOnTop(solutionList, sumNodes);  
        carryOut = 0; 
    } else { 
        if (sumNodes % 10 == 0) { 
            carryOut = sumNodes / 10; 
            solutionList = insertNodeOnTop(solutionList, 0); 
        } else { 
            carryOut = (sumNodes - (sumNodes % 10)) / 10; 
            solutionList = insertNodeOnTop(solutionList, sumNodes % 10); 
        }
    }

    list1Element = list1Element->next; 
    list2Element = list2Element->next;  
  }

  while (list1Element != NULL && list2Element == NULL) { 
    sumNodes = list1Element->val + carryOut; 

    if(sumNodes < 10) { 
        solutionList = insertNodeOnTop(solutionList, sumNodes);  
        carryOut = 0; 
    } else { 
        if (sumNodes % 10 == 0) { 
            carryOut = sumNodes / 10; 
            solutionList = insertNodeOnTop(solutionList, 0); 
        } else { 
            carryOut = (sumNodes - (sumNodes % 10)) / 10; 
            solutionList = insertNodeOnTop(solutionList, sumNodes % 10); 
        }
    }

    list1Element = list1Element->next;  
  }


  while (list1Element == NULL && list2Element != NULL) { 
    sumNodes = list2Element->val + carryOut; 

    if(sumNodes < 10) { 
        solutionList = insertNodeOnTop(solutionList, sumNodes);  
        carryOut = 0; 
    } else { 
        if (sumNodes % 10 == 0) { 
            carryOut = sumNodes / 10; 
            solutionList = insertNodeOnTop(solutionList, 0); 
        } else { 
            carryOut = (sumNodes - (sumNodes % 10)) / 10; 
            solutionList = insertNodeOnTop(solutionList, sumNodes % 10); 
        }
    }

    list2Element = list2Element->next;  
  }


  if (carryOut > 0 && (list1Element == NULL && list2Element == NULL)) { 
    solutionList = insertNodeOnTop(solutionList, carryOut); 
  }

  return reverseList(solutionList); 
}