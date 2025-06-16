class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool negative = ( (dividend < 0) ^ (divisor < 0) );
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);
        long long quotient = 0;
        while (dvd >= dvs) {
            int shift = 0;
            while (dvd >= (dvs << (shift + 1))) {
                ++shift;
            }
            dvd -= (dvs << shift);
            quotient += (1LL << shift);
        }
        if (negative) 
            quotient = -quotient;
        if (quotient > INT_MAX) 
            return INT_MAX;
        if (quotient < INT_MIN) 
            return INT_MIN;
        return (int)quotient;
    }
};