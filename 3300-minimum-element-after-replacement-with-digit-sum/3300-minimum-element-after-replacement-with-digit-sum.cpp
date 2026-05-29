class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int curr = nums[i];
            int temp =0;
            while(curr)
            {
                temp+=curr%10;
                curr/=10;
            }
            ans=min(ans, temp);
        }
        return ans;
    }
};