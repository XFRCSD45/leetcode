class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int i=1, j=n-1;
        while(i<j)
        {
            int first = i;
            int second = j;
            int f1=0, f2=0;
            while(first)
            {
                int d = first%10;
                if(d==0)
                {
                    f1=1;
                }
                first/=10;
            }
            while(second)
            {
                int d = second%10;
                if(d==0)
                {
                    f2=1;
                }
                second/=10;
            }
            if(f1== 0 && f2 ==0)
            {
                return {i,j};
            }
            i++;
            j--;
        }
        return {1,n-1};
    }
};