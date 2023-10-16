class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>>res;
      for(int i=0;i<=rowIndex;i++)
      {   vector<int>temp;
          if(i==0)
          {
              temp.push_back(1);
              res.push_back(temp);
              continue;
          }
          if(i==1)
          {
               temp.push_back(1);
               temp.push_back(1);
              res.push_back(temp);
              continue;
          }
          temp.push_back(1);
          for(int j=0;j<i-1;j++)
          {
              temp.push_back(res[i-1][j]+res[i-1][j+1]);
          } 
          temp.push_back(1);
          res.push_back(temp);
      }
      return res[rowIndex];
    }
};