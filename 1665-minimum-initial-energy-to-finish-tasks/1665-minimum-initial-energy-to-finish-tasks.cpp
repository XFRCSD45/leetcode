class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 int diffA = abs(a[0] - a[1]);
                 int diffB = abs(b[0] - b[1]);
                 if (diffA != diffB)
                     return diffA < diffB;
                 return a[1] < b[1];
             });

        int ans = 0;
        for (auto task : tasks) {
            ans = max(ans + task[0], task[1]);
        }
        return ans;
    }
};