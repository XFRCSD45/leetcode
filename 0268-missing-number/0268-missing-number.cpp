class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = nums[i];
            while (j<n && j!=-1 && nums[j] != -1) {
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
                if (j<n && nums[j] >= n) {
                    nums[j] = -1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                return i;
            }
        }
        return n;
    }
};