class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int n = s.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                ans=max(ans,(int)st.size());
            }
            else if(s[i]==')')
            {
                st.pop();
            }
            i++;
        }
        return ans;
    }
};