class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& v, int key, int k) {
        set<int>s;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]==key)
            {
                for(int j=max(0,i-k);j<=min(n-1,i+k);j++)
                {
                    s.insert(j);
                }
            }
        }
        vector<int>ans;
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};