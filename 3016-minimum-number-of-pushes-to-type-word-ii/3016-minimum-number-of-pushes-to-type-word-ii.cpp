class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            freq[word[i]-'a']++;
        }
        vector<pair<int,int>>v;
        for(int i=0;i<26;i++)
        {
            v.push_back({freq[i],i});
        }
        sort(v.begin(), v.end(), [&](pair<int,int>&a, pair<int,int>&b){
            return a.first>b.first;
        });
        int ans=0;
        int presses=0;
        for(int i=0;i<26;i++)
        {
            if(i%8==0)
            {
                presses++;
            }
            ans += (v[i].first * presses);
        }

        return ans;
    }
};