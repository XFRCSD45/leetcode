class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        int cols = n/rows;
        vector<vector<char>>v(rows,vector<char>(cols));
        int pos=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                v[i][j]=s[pos++];
            }
        }
        string ans="";
        int i=0, j=0;
        while(j<cols)
        {
            int curr=j;
            while(i<rows && j<cols)
            {
                ans+=v[i][j];
                i++;
                j++;
            }
            i=0;
            j=curr+1;
        }
         ans.erase(ans.find_last_not_of(' ') + 1);
         return ans;
    }
};