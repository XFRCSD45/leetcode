class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
                 if(nums[i]%2==0)
                 {
                      ans.push_back(nums[i]);
                     nums[i]=-1;
                 }
        }
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]!=-1)
            {
                    ans.push_back(nums[i]);
            }
            i++;
}
        return ans;
    }
};