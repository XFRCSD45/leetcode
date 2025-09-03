class Solution {
    public int numberOfPairs(int[][] points) {
        int n = points.length;
        Arrays.sort(points, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            } else {
                return Integer.compare(b[1], a[1]);
            }
        });
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int largestY = Integer.MIN_VALUE;
            for (int j = i + 1; j < n; j++) {
                int x1 = points[j][0];
                int y1 = points[j][1];
                if (y1 > y) {
                    continue;
                }

                if (y1 > largestY) {
                    ans++;
                    largestY = y1;
                }

            }
        }
        return ans;
    }
}