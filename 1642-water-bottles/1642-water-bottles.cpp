class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int rem =0;
        while(numBottles>=numExchange)
        {
            int q = numBottles/numExchange;
            rem = numBottles%numExchange;
            ans+=q;
            numBottles=q+rem;
        }
        return ans;
    }
};