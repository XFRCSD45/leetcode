class Solution {
public:
    string reverseWords(string s) {
        for(int i=0;i<s.size();)
        {
             int j=i+1;
            if(s[i]!=' ')
            {
                  
                   while(j<s.size() && s[j]!=' ')
                   {
                            j++;
                   }
                reverse(s.begin()+i, s.begin()+j);
            }
            i=j;
        }
        return s;
    }
};