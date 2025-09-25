class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>ans(101);
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]]++;
        }
        int maxi= *max_element(ans.begin(), ans.end());
        int result=0;
        for(int i=0;i<101;i++)
        {
            if(ans[i]==maxi)
            {
                result+=ans[i];
            }
        }
        return result;
    }
};