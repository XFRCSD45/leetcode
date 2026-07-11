class Solution {
public:
    void dfs(int node,vector<vector<int>>&g, vector<int>&vis, int &nodes, int &edges)
    {
        vis[node]=1;
         for(auto i:g[node])
         {  
            edges++;
             if(!vis[i])
             {
                nodes++;
                dfs(i,g,vis,nodes,edges);
             }
         }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>g(n);
        for(auto i: edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
             if(!vis[i])
             {
                int nodes=1;
                int edge=0;
                dfs(i,g,vis,nodes,edge);
                if(edge==nodes*(nodes-1))
                {
                    ans++;
                }
             }
        }
        return ans;
    }
};