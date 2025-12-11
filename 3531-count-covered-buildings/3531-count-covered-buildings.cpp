class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
     map<int, vector<int>>x, y;
     int sz=buildings.size();
     for(int i=0;i<sz;i++)
     {
        int X=buildings[i][0];
        int Y = buildings[i][1];
        x[X].push_back(Y);
        y[Y].push_back(X);
     }
     int ans=0;
     for(auto i:x)
     {
        int m = i.second.size();
        sort(i.second.begin(), i.second.end()); 
        for(int j=1;j<m-1;j++)
        {
            int currY=i.second[j];
            int len = y[currY].size();
            sort(y[currY].begin(), y[currY].end());
            if(y[currY][0]!=i.first && y[currY][len-1]!=i.first)
            {
                ans++;
            }
        }
     }
     return ans;
    }
};