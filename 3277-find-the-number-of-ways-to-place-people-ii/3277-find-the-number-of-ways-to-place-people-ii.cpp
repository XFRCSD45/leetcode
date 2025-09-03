class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] > b[1];
             });

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int largestY = INT_MIN;
            int smallestX = INT_MAX;
            int found = 0;
            int curr = 0;

            for (int j = i + 1; j < n; j++) {
                int x1 = points[j][0];
                int y1 = points[j][1];

                if (y1 <= y) {
                    if (found == 0) {
                        smallestX = x1;
                        largestY = y1;
                        curr++;
                        found = 1;
                    } else if (x1 > smallestX && y1 > largestY) {
                        smallestX = x1;
                        largestY = y1;
                        curr++;
                        found = 1;
                    }
                }
            }
            ans += curr;
        }
        return ans;
    }
};