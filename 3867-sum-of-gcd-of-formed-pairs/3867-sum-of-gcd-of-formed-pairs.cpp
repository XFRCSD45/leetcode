class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            temp[i]=__gcd(nums[i], maxi);
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        int i=0, j=n-1;
        while(i<j)
        {
            ans= 0LL + ans + __gcd(temp[i], temp[j]);
            i++;
            j--;
        }
        return ans;
    }
};