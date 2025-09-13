class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        sort(s.begin(), s.end());
        int maxV=0;
        int maxC=0;
        int currC=0;
        int currV=0;
        int ans=1;
        if(isVowel(s[0]))
        {
            maxV=1;
            currV=1;
        }
        else
        {
            maxC=1;
            currC=1;
        }
        int n = s.size();
        for(int i=1;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                if(s[i]==s[i-1])
                {
                    currV++;
                }
                else
                {
                    maxV = max(maxV, currV);
                    currV=1;
                }
            }
            else 
            {
                if(s[i]==s[i-1])
                {
                    currC++;
                }
                else
                {
                    maxC = max(maxC, currC);
                    currC=1;
                }
            }
        }
        maxC = max(maxC, currC);
        maxV = max(maxV, currV);
        ans = max(ans,maxC+maxV);
        return ans;
    }
};