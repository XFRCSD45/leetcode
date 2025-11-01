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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* ans=head;
        ListNode* temp = head;
        unordered_map<int,bool>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=true;
        }
        while(temp!=NULL&& m[temp->val])
        {
            temp=temp->next;
        }
        ans=temp;
        if(!ans){
            return NULL;
        }
        while( temp->next!=NULL)
        {
            if(m[temp->next->val])
            {
                temp->next = temp->next->next;

            }
            else
            {

            temp=temp->next;
            }
        }
        return ans;
    }
};