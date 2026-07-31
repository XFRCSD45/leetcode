class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            freq[word[i]-'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int ans=0;
        int presses=0;
        for(int i=0;i<26;i++)
        {
            if(i%8==0)
            {
                presses++;
            }
            ans += (freq[i] * presses);
        }

        return ans;
    }
};