class Solution {
    public double maxAverageRatio(int[][] classes, int extra) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            double gainA = (double) (a[1] - a[0]) / ((long) a[1] * (a[1] + 1));
            double gainB = (double) (b[1] - b[0]) / ((long) b[1] * (b[1] + 1));
            return Double.compare(gainB, gainA);
        });

        for (int[] c : classes) {
            pq.offer(new int[] { c[0], c[1] });
        }

        for (int i = 0; i < extra; i++) {
            int[] top = pq.poll();
            top[0] += 1;
            top[1] += 1;
            pq.offer(top);
        }
        
        double sum = 0.0;
        for (int[] c : pq) {
            sum += (double) c[0] / c[1];
        }

        return sum / classes.length;
    }
}