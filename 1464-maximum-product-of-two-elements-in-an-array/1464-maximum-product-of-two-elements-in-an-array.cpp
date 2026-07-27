class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int pa=a;
            a=max(a,nums[i]);
            b=max(b,min(pa,nums[i]));
        }
        a--;
        b--;
        return a*b;
    }
};