class Solution {
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
        int pos = -1;
        int n = w.size();
        for (int i = 0; i < n; i++) {
            if (w[i] == e) {
                pos = i + 1;
                break;
            }
        }
        if (pos == -1) {
            return {};
        }
        vector<vector<int>> g(n + 1);
        vector<vector<int>> p(n + 1);
        p[0] = {-1};
        for (int i = 0; i < n; i++) {
            int len = b.size();
            len--;
            int count = 0;
            while (len >= 0) {
                if (w[i][len] != b[len]) {
                    count++;
                }
                len--;
            }
            if (count == 1) {
                g[0].push_back(i + 1);
                g[i + 1].push_back(0);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                int len = w[j].size();
                len--;
                while (len >= 0) {
                    if (w[i][len] != w[j][len]) {
                        count++;
                    }
                    len--;
                }
                if (count == 1) {
                    g[i + 1].push_back(j + 1);
                    g[j + 1].push_back(i + 1);
                }
            }
        }
        vector<int> dist(n + 1, 1e9);
        queue<pair<int, int>> q;
        dist[0] = 0;

        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto i : g[curr.first]) {
                if (curr.second + 1 < dist[i]) {
                    dist[i] = curr.second + 1;
                    q.push({i, dist[i]});
                    p[i].clear();
                    p[i].push_back(curr.first);
                } else if (curr.second + 1 == dist[i]) {
                    p[i].push_back(curr.first);
                }
            }
        }
        if (dist[pos] == 1e9) {
            return {};
        }
        vector<vector<string>> paths;
        vector<string> path;
        function<void(int)> find_paths = [&](int u) -> void {
            if (u == -1) {
                paths.push_back(path);
                return;
            }
            for (int par : p[u]) {
                if (u == 0) {
                    path.push_back(b);
                } else {

                    path.push_back(w[u - 1]);
                }
                find_paths(par);
                path.pop_back();
            }
        };
        find_paths(pos);
        for (int i=0;i<paths.size();i++) {
            reverse(paths[i].begin(), paths[i].end());
        }
        return paths;
    }
};