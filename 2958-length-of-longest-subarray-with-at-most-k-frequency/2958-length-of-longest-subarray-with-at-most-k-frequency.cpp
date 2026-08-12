class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        int i=0, j=0, ans=0;
        while(j<n)
        {
            // cout<<i<<" "<<j<<" "<<ans<<endl;
            if(m[nums[j]]==k)
            {

                ans=max(ans, j-i); 
                // cout<<"Finding ans at i , j"<<i<<" "<<j<<ans<<endl;
                while(!(nums[i]==nums[j]))
                {
                    // cout<<i<<" "<<m[nums[i]]<<endl;
                    m[nums[i]]--;
                    i++;
                }
                m[nums[i]]--;
                i++;
            }
            m[nums[j]]++;
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};