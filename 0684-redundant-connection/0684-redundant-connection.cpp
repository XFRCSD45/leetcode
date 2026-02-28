class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n)
    {
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    void unionByRank(int u, int v)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)
        {
            return;
        }
        else if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu])
        {
            parent[pv]=pu;
        }
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n = edges.size();
        DSU dsu(n);
        for(auto i:edges)
        {
            int u = i[0];
            int v = i[1];
            int pu = dsu.findParent(u);
            int pv = dsu.findParent(v);
            if(pu==pv)
            {
                ans={u,v};
            }
            dsu.unionByRank(u,v);
        }
        return ans;
    }
};