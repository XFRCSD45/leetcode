class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        int n = text.size();
        for(int i=0;i<n;i++)
        {
            freq[text[i]-'a']++;
        }
        int ans=n;
        for(int i=0;i<26;i++)
        {
            if(i==0||i==1||i==13)
            {
                ans=min(ans,freq[i]);
            }
            else if(i==11 || i==14)
            {
                ans=min(ans,freq[i]/2);
            }
        }
        return ans;
    }
};