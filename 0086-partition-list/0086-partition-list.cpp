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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
        {
           return NULL;
        }
        ListNode* ans=NULL;
        ListNode* curr=ans;
        ListNode* temp=head;
        if(temp->val<x)
        {
            ans=new ListNode(temp->val);
            curr=ans;
            temp=temp->next;
         }
        
        while(temp!=NULL )
        {
                if(ans==NULL && temp->val<x)
                {
                      ans=new ListNode(temp->val);
                     curr=ans;
                    temp=temp->next;
                }
            else if(temp->val<x)
            {
                 curr->next=new ListNode(temp->val);
                curr=curr->next;
                temp=temp->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        
        temp=head;
        while(temp!=NULL)
        {
             if(temp->val>=x )
             {    
                 if(curr!=NULL)
                 {
                     curr->next=new ListNode(temp->val);
                curr=curr->next;
                temp=temp->next;
                 }
                 else
                 {
                      ans=new ListNode(temp->val);
                     curr=ans;
                    temp=temp->next;    
                 }
             }
            else
            {
                temp=temp->next;
            }
            
        }
        return ans;
    }
};