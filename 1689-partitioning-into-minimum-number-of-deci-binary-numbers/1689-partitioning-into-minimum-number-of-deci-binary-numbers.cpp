class Solution {
public:
    int minPartitions(string s) {
        int maxi=0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int curr  = s[i]-'0';
            maxi=max(curr,maxi);
        }
        return maxi;
    }
};