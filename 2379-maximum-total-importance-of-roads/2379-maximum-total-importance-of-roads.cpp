class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n);
        for(int i=0;i<roads.size();i++)
        {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        sort(degree.begin(), degree.end(), greater<int>());
         long long  ans=0;
         for(int i=0;i<n;i++)
         {
            long long temp=(n-i)*(long long )(degree[i]);
            ans+=temp;
         }
        // for(int i=n;i>=1;i++)
        // {
        //     ;
        // }
        return ans;
    }
};