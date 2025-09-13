class Solution {
public:

    void solve(int n, int open, int currOpen, string s, vector<string>&ans)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return;
        }
        if(currOpen >=1)
        {
            string temp = s+ ')';
            solve(n, open ,currOpen-1, temp, ans);
        }
        if(open<n)
        {
            string temp= s + '(';
            solve(n, open+1, currOpen+1, temp, ans);
        }
        
        
    }
    vector<string> generateParenthesis(int n) {
        int open =0, currOpen =0;
        vector<string>ans;
        string s ="";
        solve(n,open , currOpen, s, ans);
        return ans;
    }
};