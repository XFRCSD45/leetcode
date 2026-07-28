class Solution {
public:
    int solve(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];
        vector<int> secondWindowSum(n, 0);

        for (int start = 0; start + secondLen <= n; start++) {
            secondWindowSum[start] =
                prefix[start + secondLen] - prefix[start];
        }
        vector<int> leftBest(n, 0);
        leftBest[0] = secondWindowSum[0];

        for (int i = 1; i < n; i++) {
            leftBest[i] = max(leftBest[i - 1], secondWindowSum[i]);
        }
        vector<int> rightBest(n, 0);
        rightBest[n - secondLen] = secondWindowSum[n - secondLen];

        for (int i = n - secondLen - 1; i >= 0; i--) {
            rightBest[i] = max(rightBest[i + 1], secondWindowSum[i]);
        }

        int answer = 0;
        for (int start = 0; start + firstLen <= n; start++) {

            int end = start + firstLen - 1;

            int firstWindowSum =
                prefix[end + 1] - prefix[start];
            if (start >= secondLen)
                answer = max(answer,
                             firstWindowSum + leftBest[start - secondLen]);
            if (end + 1 <= n - secondLen)
                answer = max(answer,
                             firstWindowSum + rightBest[end + 1]);
        }

        return answer;
    }

    int maxSumTwoNoOverlap(vector<int>& nums,
                           int firstLen,
                           int secondLen) {

        // return max(
        //     solve(nums, firstLen, secondLen),
        //     solve(nums, secondLen, firstLen)
        // );
        return  solve(nums, firstLen, secondLen);
    }
};