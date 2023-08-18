#include<bits/stdc++.h>
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
     vector<vector<int>>adj(n);
        for(int i=0;i<r.size();i++)
        {
           adj[r[i][0]].push_back(r[i][1]);
            adj[r[i][1]].push_back(r[i][0]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int temp=adj[i].size();
            for(int j=i+1;j<n;j++)
            {     
                 temp=temp+adj[j].size();
                 auto it=find(adj[j].begin(),adj[j].end(),i);
                if(it!=adj[j].end())
                {
                    temp--;
                }
                ans=max(temp,ans);
                temp=adj[i].size();
            }
            
             
           
        }
        
        return ans;
    }
};