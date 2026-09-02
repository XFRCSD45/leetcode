class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;
    for (int n : s) {
        if (s.count(n - 1)) continue;
        int len = 1;
        while (s.count(n + len)) len++;
        ans = max(ans, len);
    }
    return ans;
}
};