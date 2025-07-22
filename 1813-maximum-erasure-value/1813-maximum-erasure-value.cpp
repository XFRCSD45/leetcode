class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int i=0, j=1;
        int sum=v[i];
        int n = v.size();
        int ans=v[0];
        vector<int>vec(100001,-1);
        vec[v[i]]=1;
        while(i<n)
        {
            while(j<n)
            {
                if(vec[v[j]]==-1)
                {
                    sum+=v[j];
                    vec[v[j]]=1;
                    j++;
                }
                else
                {
                    vec[v[i]]=-1;
                    sum-=v[i];
                    break;
                }
                ans=max(ans,sum);
            }
            i++;
        }
        return ans;
    }
};