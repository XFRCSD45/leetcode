class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=n-1;i>=0;i--)
        {
            int curr = nums[i];
            while(curr)
            {
                int d = curr%10;
                ans.push_back(d);
                curr/=10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};