/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
        {
            return head;
        }
        int n =0;
        ListNode* curr = head;
        ListNode* tail=NULL;
        while(curr!=NULL)
        {
            n++;
            if(curr->next == NULL)
            {
                tail = curr;
            }
            curr=curr->next;
        }
        k %=n;
        if(k==0)
        {
            return head;
        }
        int target = n-k;
        curr = head;
        while(--target && curr!=NULL) 
        {
            curr=curr->next;
        }
        if(curr!=NULL)
        {
            ListNode* temp = curr->next;
            tail->next =head;
            head = temp;
            curr->next = NULL;
        }
        return head;
    }
};