class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
        prefix[0] = customers[0] == 'N' ? 1 : 0;
        for (int i = 1; i < n; i++) {

            prefix[i] = prefix[i - 1] + (customers[i] == 'N' ? 1 : 0);
        }
        prefix[n] = prefix[n - 1];
        for (int i = n - 1; i >= 0; i--) {

            suffix[i] = suffix[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int mini = n;
        int ans = n;
        for (int i = 0; i < n; i++) {
            int curr = prefix[i] + suffix[i];
            if (customers[i] == 'N') {
                curr--;
            }
            if (curr < mini) {
                ans = i;
                mini = curr;
            }
        }
        if (prefix[n] < mini) {
            return n;
        }
        return ans;
    }
};