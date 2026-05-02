class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int temp = i;
            int f=0;
            while(temp)
            {
                int d = temp%10;
                if(d == 3 || d== 4 || d== 7)
                {
                    f=0;
                    break;
                }
                if(d == 2 || d==5 || d==6 || d==9)
                {
                    f=1;
                }
                temp/=10;
            }
            if(f)
            {
                ans++;
            }
        }
        return ans;
    }
};