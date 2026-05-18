class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);

        queue<pair<int,int>> q;

        q.push({0,0});

        vis[0] = 1;

        while(!q.empty()) {

            auto [node, steps] = q.front();
            q.pop();

            if(node == n - 1)
                return steps;
            if(node + 1 < n && !vis[node + 1]) {
                vis[node + 1] = 1;
                q.push({node + 1, steps + 1});
            }

            if(node - 1 >= 0 && !vis[node - 1]) {
                vis[node - 1] = 1;
                q.push({node - 1, steps + 1});
            }
            for(auto idx : mp[arr[node]]) {
                if(!vis[idx]) {
                    vis[idx] = 1;
                    q.push({idx, steps + 1});
                }
            }
            mp[arr[node]].clear();
        }

        return -1;
    }
};