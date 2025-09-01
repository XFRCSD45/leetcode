class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        for (int i = 0; i < n; i++) {
            int total = classes[i][1];
            int pass = classes[i][0];
            pq.push({gain(pass, total), i});
        }
        for (int i = 1; i <= extra && !pq.empty(); i++) {
            auto [change, idx] = pq.top();
            pq.pop();
            classes[idx][0] += 1;
            classes[idx][1] += 1;
            pq.push({gain(classes[idx][0], classes[idx][1]), idx});
        }
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            sum += (double)classes[i][0] / classes[i][1];
        }
        double average = sum / n;
        return average;
    }
};