class Solution {
public:
    int maximumGain(string s, int x, int y) {
    stack<char> st;
        int count=0;
    
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() && x>=y && s[i]=='b' && st.top()=='a')
            {
                st.pop();
                count=count+x;
            }
            else if(!st.empty() && y>=x && s[i]=='a' && st.top()=='b')
            {
                st.pop();
                count=count+y;
            } 
            else
            {
                st.push(s[i]);
            }
        }
        string rem = "";
        while(!st.empty())
        {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(),rem.end());

        for(int i=0;i<rem.length();i++)
        {
            if(!st.empty() && x<=y && rem[i]=='b' && st.top()=='a')
            {
                st.pop();
                count=count+x;
            }
            else if(!st.empty() && y<=x && rem[i]=='a' && st.top()=='b')
            {
                st.pop();
                count=count+y;
            } 
            else
            {
                st.push(rem[i]);
            }
        }
        
        return count;
    }
};