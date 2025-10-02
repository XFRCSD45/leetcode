class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int rem =0;
        while(numBottles>=numExchange)
        {
            ans++;
            numBottles-=numExchange;
            numBottles++;
            numExchange++;
        }
        return ans;
    }
};