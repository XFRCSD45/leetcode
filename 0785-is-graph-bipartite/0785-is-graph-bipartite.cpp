class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        int m = graph[0].size();
        vector<int>color(n, -1);
        function<bool(int , int)> dfs=[&](int curr, int col)->bool
        {
             color[curr]=col;
             for(auto i : graph[curr])
             {
                  if(color[i]==-1)
                  {
                      if(dfs(i, !col)==false)
                      {
                        return false;
                      }
                  }
                  else if(color[i]==col)
                  {
                    return false;
                  }
             }
             return true;
        };
        for(int i=0;i<n;i++)
        {
              if(color[i]==-1)
              {
                if(dfs(i,0)==false)
                {
                    return false;
                }

              }
        }
        return true;
    }
};