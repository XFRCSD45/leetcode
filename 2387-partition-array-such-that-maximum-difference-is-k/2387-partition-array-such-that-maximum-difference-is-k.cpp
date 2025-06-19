class Solution {
public:
    int partitionArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int ans=0;
        int n= v.size();
        int i=0;
        int mini=v[0];
        int maxi=v[0]+k;
        while(i<n)
        {
            while(i<n && v[i]<=maxi)
            {
                i++;
            }
            ans++;
            if(i!=n)
            {
                mini=v[i];
                maxi=mini+k;
            }
        }
        return ans;
    }
};