class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows ==1)
        {
            return ans;
        }
        int curr=1;
        ans.push_back({1,1});
        for(int i=3;i<=numRows;i++)
        {
            vector<int>temp;
            temp.push_back(1);
             for(int j=1;j<=i-2;j++)
             {
                temp.push_back(ans[curr][j-1]+ans[curr][j]);
             }
             temp.push_back(1);
             ans.push_back(temp);
             curr++;
        }
        return ans;
    }
};