class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>ss;
        int n = s.size();
        for(int i=0;i<=n-k;i++)
        {
            string temp=s.substr(i,k);
            ss.insert(temp);
        }
        if(ss.size()==pow(2,k))
        {
            return true;
        }
        return false;
    }
};