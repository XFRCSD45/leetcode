class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>ans(101);

        int maxi=0, result=0;
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]]++;
            if(ans[nums[i]]>maxi)
            {
                maxi=ans[nums[i]];
                result=ans[nums[i]];
            }
            else if(ans[nums[i]]==maxi)
            {
                result+=ans[nums[i]];
            }
        }
        
        return result;
    }
};