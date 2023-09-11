class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
      
          int n=g.size();
        vector<queue<int>>ans(n+1);
        for(int i=0;i<n;i++)
        {
            ans[g[i]].push(i); 
        }
        vector<vector<int>>res;
        for(int i=1;i<=n;i++)
        {
              if(ans[i].size()>0)
              {
                  
                 
                  while(!ans[i].empty())
                  { vector<int>temp;
                         for(int j=1;j<=i;j++)
                         {
                             temp.push_back(ans[i].front());
                             ans[i].pop();
                         }
                    res.push_back(temp);
                  }
                 
              }
        }
        return res;
    }
};