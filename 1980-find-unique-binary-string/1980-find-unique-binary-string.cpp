class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_map<string,bool>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=true;
        }
        for (int i = 0; i < (1 << n); i++) {
        string s;
         for (int j = n - 1; j >= 0; --j)
            s += ((i >> j) & 1) ? '1' : '0';
        if(!m[s])
        {
            return s;
        }
        }
        return "";
    }
};