class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int ans = 0;
        sort(reservedSeats.begin(), reservedSeats.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] < b[1];
                 }
                 return a[0] < b[0];
             });
        int rows = 0;
        int i = 0;
        while (i < m) {
            int currRow = reservedSeats[i][0];
            int j = i;
            int first = 1, second = 1, third = 1;
            while (j < m && reservedSeats[j][0] == reservedSeats[i][0]) {
                if (reservedSeats[j][1] >= 2 && reservedSeats[j][1] <= 5) {
                    first = 0;
                }
                if (reservedSeats[j][1] >= 4 && reservedSeats[j][1] <= 7) {
                    second = 0;
                }
                if (reservedSeats[j][1] >= 6 && reservedSeats[j][1] <= 9) {
                    third = 0;
                }
                j++;
            }
            if (first && third) {
                ans += 2;
            } else if (first || second || third) {
                ans += 1;
            }
            i = j;
            rows++;
        }
        ans = ans + (n - rows) * 2;
        return ans;
    }
};