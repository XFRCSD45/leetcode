class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       unordered_map<string, bool>m;
       int n = words.size();
       vector<string>ans;
       for(int i=0;i<n;)
       {
        string curr =  words[i];
        sort(curr.begin(), curr.end());
        ans.push_back(words[i]);
        int j=i+1;
        while(j<n)
        {

           string temp = words[j];
           sort(temp.begin(), temp.end());
           if(curr == temp)
           {
             j++;
           }
           else
           {
            break;
           }
        }
        i=j;
       }
       return ans;
    }
};