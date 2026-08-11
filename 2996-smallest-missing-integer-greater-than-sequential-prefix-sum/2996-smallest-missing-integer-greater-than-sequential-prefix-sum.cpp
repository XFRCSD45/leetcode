class Solution {
public:
    int missingInteger(vector<int>& nums) {
     int sum =nums[0];
     int n = nums.size();
     int i=0;
     while(i+1<n && (nums[i+1]==nums[i]+1))
     {
        sum+=nums[i+1];
        i++;
     }
        sort(nums.begin()+i, nums.end());
        auto itr = lower_bound(nums.begin()+i, nums.end(), sum) - nums.begin();
        if(itr== n || nums[itr]>sum )
        {
            return sum;
        }
        i=itr;
        while(i+1<n && (nums[i+1]==nums[i]+1 || nums[i+1]==nums[i]))
        {
            i++;
        }
        return nums[i]+1;
    }
};