class Solution {
public:
    int minDeletions(string s) {
         
        unordered_map<int,bool>m;
        unordered_map<char,int>mp;
        sort(s.begin(), s.end());
        for(auto i: s)
        {
               mp[i]++;
        }
        int count=0;
        for(auto i: mp)
        {
            int freq=i.second;
            while(freq>0 && m[freq]!=false)
            {
                     freq--;
                count++;
            }
            m[freq]=true;
        }
        return count;
    }
};