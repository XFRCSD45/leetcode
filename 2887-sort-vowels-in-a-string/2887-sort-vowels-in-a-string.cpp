class Solution {
public:
    string sortVowels(string s) {
        map<char,bool>m;
        vector<char>v = {'A','E', 'I','O','U', 'a', 'e', 'i', 'o', 'u' };
        for(auto i:v)
        {
            m[i]=true;
        }
        int n = s.size();
        vector<char>vec;
        for(int i=0;i<n;i++)
        {
            if(m[s[i]])
            {
                vec.push_back(s[i]);
                s[i]='#';
            }
        }
        sort(vec.begin(), vec.end());
        int pos=0;
        for(int i=0;i<n && pos<vec.size();i++)
        {
            if(s[i]=='#')
            {
                s[i]=vec[pos++];
            }
        }
        return s;
    }
};