class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum=0, ans=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum+=nums[i];
            if(abs(2*sum-total)%2==0)
            {
                ans++;
            }
        }   
        return ans;
    }
};