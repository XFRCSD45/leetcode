class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        int n= strs.size();
        for(int i=0;i<n;i++)
        {
            string temp(26,'0');
            for(int j=0;j<strs[i].size();j++)
            {
                int curr = strs[i][j] -'a';
                int tempCurr=temp[curr]-'0';
                tempCurr++;
                temp[curr]=tempCurr+'0';
            }
            m[temp].push_back(strs[i]);
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};