class Solution {
public:
    static bool comparator(pair<int,int>a, pair<int,int>b)
    {
               if(a.first<b.first)
               {
                   return true;
               }
               else if(a.first==b.first)
                 {
                    if(a.second<b.second)
                        return true;
                  }
        
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        vector<pair<int,int>>temp;
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
              for(int j=0;j<mat[i].size();j++)
              {
                     if(mat[i][j]==1)
                     {
                           count++;
                     }
                  else
                  {
                       break;
                  }
              }
            temp.push_back(make_pair(count,i));
        }
        
       sort(temp.begin(),temp.end(),comparator);
        for(int i=0;i<k;i++)
        {
              ans.push_back(temp[i].second);
        }
        return ans;
    }
};