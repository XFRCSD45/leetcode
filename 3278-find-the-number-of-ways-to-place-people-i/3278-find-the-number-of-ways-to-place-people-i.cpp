class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n ; i++) {
            int x = points[i][0];
            int y = points[i][1];
            for (int j = 0; j < n; j++) {
                int x1 = points[j][0];
                int y1 = points[j][1];
                if ((i == j) || (x1 < x || y1 > y)) {
                    continue;
                }
                int f = 1;
                for (int k = 0; k < n; k++) {
                    int x2 = points[k][0];
                    int y2 = points[k][1];
                    if ((k == i || k == j) || (x1 < x || y1 > y)) {
                        continue;
                    }
                    if ((x2 <= x1 && x2 >= x) && (y2 <= y && y2 >= y1)) {
                        f = 0;
                    }
                }
                if (f) {
                    ans++;
                }
            }
        }
        return ans;
    }
};