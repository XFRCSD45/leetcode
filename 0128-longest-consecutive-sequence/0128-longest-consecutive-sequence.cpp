class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m, vis;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]]=true;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[nums[i]])
            {
                int next=0, prev=0;
                vis[nums[i]]=true;
                int j=nums[i]+1;
                int k=nums[i]-1;
                while(m[j] && !vis[j])
                {
                    vis[j]=true;
                    j++;
                    next++;
                }
                while(m[k] && !vis[k])
                {
                    vis[k]=true;
                    k--;
                    prev++;
                }
                ans=max(ans, next+prev+1);
            }
            i++;
        }
        return ans;
    }
};