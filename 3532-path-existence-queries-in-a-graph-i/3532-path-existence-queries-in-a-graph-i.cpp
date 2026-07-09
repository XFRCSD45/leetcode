class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n,-1);
        int currParent =0;
        int i=0;
        while(i<n)
        {
            int curr = nums[i];
            int j =i+1;
            int next = curr + maxDiff;
            while(j<n && nums[j]<=next )
            {
                next=nums[j]+maxDiff;
                j++;
            }
            for(int l=i;l<j;l++)
            {
                // cout<<"inside Parent "<<l<<endl;
                parent[l]=currParent;
            }
            i=j;
            currParent++;
        }
        // for(int k=0;k<n;k++)
        // {
        //     cout<<parent[k]<<" ";
        // }
        // cout<<endl;
        vector<bool>ans(queries.size(), false);
        for(int k=0;k<queries.size();k++)
        {
            int u = queries[k][0];
            int v = queries[k][1];
            if(parent[u]==parent[v])
            {
                ans[k]=true;
            }
        }
        return ans;
    }
};