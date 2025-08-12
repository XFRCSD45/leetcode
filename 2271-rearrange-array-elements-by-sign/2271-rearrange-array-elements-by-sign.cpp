class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int pos=-1, neg=-1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=1 && pos==-1 )
            {
                pos=i;
            }
            else if(nums[i]<1 && neg==-1)
            {
                neg=i;
            }
            else if(pos!=-1 && neg!=-1)
            {
                break;
            }
        }
        while(ans.size()<n)
        {
            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);
            pos++;
            neg++;
            while(pos<n && nums[pos]<1)
            {
                pos++;
            }
            while(neg<n && nums[neg]>=1)
            {
                neg++;
            }
        }

        return ans;
    }
};