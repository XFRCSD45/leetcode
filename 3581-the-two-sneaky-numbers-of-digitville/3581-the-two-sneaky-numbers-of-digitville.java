class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length;
        int i = 0;
        while (i < n) {
            int corrIdx = nums[i];
            if (nums[i] != nums[corrIdx]) {
                int temp = nums[i];
                nums[i] = nums[corrIdx];
                nums[corrIdx] = temp;
            } else {
                i++;
            }
        }
        return new int[]{nums[n - 1], nums[n - 2]};
    }
}