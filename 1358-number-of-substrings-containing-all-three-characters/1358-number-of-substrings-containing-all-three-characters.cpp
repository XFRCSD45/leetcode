class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int  n = s.size();
        int i=0, j=0;
        unordered_map<char,int>m;
        while(j<n)
        {
            m[s[j]]++;
            while(m['a'] && m['b'] && m['c'])
                {
                    ans+=(n-j);
                    m[s[i]]--;
                    i++;
                }
                j++;
        }
        return ans;
    }
};