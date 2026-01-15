class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(vBars.begin(), vBars.end());
        sort(hBars.begin(), hBars.end());
        int hMaxi=1, vMaxi=1;
        int hCurr=1, vCurr=1;
        for(int i=1;i<hBars.size();i++)
        {
            if((hBars[i]-hBars[i-1])==1)
            {
                hCurr++;
                hMaxi=max(hMaxi,hCurr);
            }
            else
            {
                hCurr=1;
            }
        }
        for(int i=1;i<vBars.size();i++)
        {
            if((vBars[i]-vBars[i-1])==1)
            {
                vCurr++;
                vMaxi=max(vMaxi,vCurr);
            }
            else
            {
                vCurr=1;
            }
        }
        int ans = min(hMaxi,vMaxi) + 1;
        return ans*ans;
    }
};