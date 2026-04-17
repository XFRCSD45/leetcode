class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        int ans=n+1;
        for(int i=0;i<n;i++)
        {
            if(m.contains(nums[i]))
            {
                ans=min(ans,i-m[nums[i]]);
            }
            int rev=0;
            int curr=nums[i];
            while(curr)
            {
                int d= curr%10;
                rev*=10;
                rev+=d;
                curr/=10;
            }
            m[rev]=i;
        }
        return ans==n+1?-1:ans;
    }
};