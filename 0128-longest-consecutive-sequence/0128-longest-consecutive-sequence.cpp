class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        unordered_map<int, bool> vis;
        unordered_map<int, int> ans;
        int res = 0;
        int i = 0;
        while (i < n) {
            if (!vis[nums[i]]) {
                vis[nums[i]] = true;
                int j = nums[i] + 1;
                int temp = 1;
                while (m[j]) {
                    if(vis[j])
                    {
                        temp+=ans[j];
                        break;
                    }
                    vis[j] = true;
                    j++;
                    temp++;
                }
                ans[nums[i]]=temp;
                res = max(res, temp);
            }
            i++;
        }
        return res;
    }
};