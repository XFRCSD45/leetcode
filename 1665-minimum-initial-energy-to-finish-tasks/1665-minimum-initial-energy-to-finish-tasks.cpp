class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 int diffA = abs(a[0] - a[1]);
                 int diffB = abs(b[0] - b[1]);
                 if (diffA != diffB)
                     return diffA > diffB;
                 return a[1] < b[1];
             });

        int low = 0, high = INT_MAX;
        int ans = INT_MAX;
        function<bool(int)> check = [&](int K) -> bool {
            int curr = K;
            for (int i = 0; i < tasks.size(); i++) {
                if (curr < tasks[i][1]) {
                    return false;
                }
                curr -= tasks[i][0];
            }
            return true;
        };
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};