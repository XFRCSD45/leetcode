class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>vec(15);
        for(int i=0;i<n;i++)
        {
            int bits = __builtin_popcount(arr[i]);
            vec[bits].push_back(arr[i]);
        }
        vector<int>ans;
        for(int i=0;i<=14;i++)
        {
            sort(vec[i].begin(), vec[i].end());
            for(int num : vec[i])
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};