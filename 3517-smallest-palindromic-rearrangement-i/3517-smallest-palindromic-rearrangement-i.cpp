class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        string ans="";
        char ch='*';
        for(int i=0;i<26;i++)
        {
            int f = freq[i]/2;
            string temp(f,'a'+i);
            if(freq[i]&1)
            {
                ch = 'a'+i;
            }
            ans+=temp;
        }
        string temp= ans;
        if(ch!='*')
        {
            ans+=ch;
        }
        reverse(temp.begin(), temp.end());
        ans+=temp;
        return ans;
    }
};