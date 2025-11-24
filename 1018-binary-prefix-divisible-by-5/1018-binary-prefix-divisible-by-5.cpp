class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
     vector<bool>ans;
     int n = nums.size();
     int curr=0;
     for(int i=0;i<n;i++)
     {
         curr = ((curr << 1) + nums[i])%5;
          ans.push_back(curr==0);
     } 
     return ans;  
    }
};