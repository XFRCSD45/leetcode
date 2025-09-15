class Solution {
public:
    int canBeTypedWords(string text, string b) {
        map<char, bool>m;
        for(auto c:b)
        {
            m[c]=true;
        }
           stringstream ss(text);
        string word;
        vector<string> words;

        while (ss >> word){
            words.push_back(word);
        }
        int count=0;
        for(auto i:words)
        {
            for(auto c:i)
            {
                if(m[c])
                {
                    count++;
                    break;
                }
            }
        }
        return words.size() - count;
    }
};