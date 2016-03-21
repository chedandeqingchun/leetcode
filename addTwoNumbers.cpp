/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* listInsertTail(ListNode* &pHead, ListNode* &pNewNode) {
        ListNode *pTemp = NULL;
        for (pTemp = pHead; pTemp != NULL; pTemp = pTemp->next) {
            if (pTemp->next == NULL) {
                pNewNode->next = NULL;
                pTemp->next = pNewNode;
                break;
            }
        }
        return pHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pHead = new ListNode(1);
        int nCarry = 0;
        pHead->val = -1;
        pHead->next = NULL;
        
        while (l1 != NULL || l2 != NULL) {
            ListNode *pData = new ListNode(1);
            if (l1 != NULL && l2 != NULL) {
               pData->val = l1->val + l2->val + nCarry;
               nCarry = pData->val / 10;
               pData->val = pData->val % 10;
               listInsertTail(pHead, pData);
               l1 = l1->next;
               l2 = l2->next;
            } else if (l1 != NULL) {
                pData->val = l1->val + nCarry;
                nCarry = pData->val / 10;
                pData->val = pData->val % 10;
                listInsertTail(pHead, pData);
                l1 = l1->next;
            } else if (l2 != NULL) {
                pData->val = l2->val + nCarry;
                nCarry = pData->val / 10;
                pData->val = pData->val % 10;
                listInsertTail(pHead, pData);
                l2 = l2->next;
            }
        }
        
        if (nCarry != 0) {
           ListNode *pData = new ListNode(1);;
           pData->val = nCarry;
           nCarry = 0;
           listInsertTail(pHead, pData);
        }
        
        return pHead->next;
    }
};