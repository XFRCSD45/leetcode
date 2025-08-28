class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 m[i-j].push_back(grid[i][j]);
            }
        }
        for(auto i : m)
        {
             if(i.first < 0)
             {
                 sort(m[i.first].begin(), m[i.first].end(), greater<int>());
             }
             else
             {
                sort(m[i.first].begin(), m[i.first].end());
             }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 grid[i][j]=m[i-j].back();
                 m[i-j].pop_back();
            }
        }
        return grid;
    }
};