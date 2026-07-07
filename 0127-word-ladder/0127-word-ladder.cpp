class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, bool> m, vis;
        for (auto s : wordList) {
            m[s] = true;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int n = beginWord.size();
        vis[beginWord]=true;
        while (!q.empty()) {
            pair<string, int> p = q.front();
            string curr = p.first;
            int d = p.second;
            cout<<curr<<" "<<d<<endl;
            q.pop();
            if (p.first == endWord) {
                return d;
            }
            for (int i = 0; i < n; i++) {
                for (int j= 0; j < 26; j++) {
                    if('a'+j !=curr[i])
                    {
                        string temp = curr;
                        temp[i]='a'+j;
                        if(m[temp] && !vis[temp])
                        {
                            vis[temp]=true;
                            q.push({temp, d+1});
                        }
                    }
                }
            }
        }

        return 0;
    }
};