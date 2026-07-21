class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int i = 0;
        int mx = 0;
        int prev = 0;

        while (i < n) {
            if (s[i] == '0') {
                prev++;
                i++;
            } else {
                while (i < n && s[i] == '1')
                    i++;

                int cnt = 0;
                while (i < n && s[i] == '0') {
                    cnt++;
                    i++;
                }

                if (prev > 0 && cnt > 0)
                    mx = max(mx, prev + cnt);

                prev = cnt;
            }
        }

        int ans = 0;
        for (char c : s)
            if (c == '1')
                ans++;

        return ans + mx;
    }
};