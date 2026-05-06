class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n =  boxGrid.size();
        int m = boxGrid[0].size();
        for(int i=0;i<n;i++)
        {
            priority_queue<int>pq;
            for(int j=m-1;j>=0;j--)
            {
                if(boxGrid[i][j]=='*')
                {
                    pq=priority_queue<int>();
                }
                else if(boxGrid[i][j]=='.')
                {
                    pq.push(j);
                }
                else
                {
                    if(!pq.empty())
                    {
                        boxGrid[i][pq.top()]='#';
                        boxGrid[i][j]='.';
                        pq.push(j);
                        pq.pop();
                    }
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<boxGrid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<vector<char>>ans(m, vector<char>(n, '.'));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[j][i]=boxGrid[n-1-i][j];
            }
        }
        return ans;

    }
};