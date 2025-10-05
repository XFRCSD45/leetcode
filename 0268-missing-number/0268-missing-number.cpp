class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < n && nums[i] != -1) {
                int j = nums[i];
                while (nums[j] != -1) {
                    if (nums[j] >= n) {
                        nums[j] = -1;
                        break;
                    }
                    int temp = nums[j];
                    nums[j] = -1;
                    j = temp;
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