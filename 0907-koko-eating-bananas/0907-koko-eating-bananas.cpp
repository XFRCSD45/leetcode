class Solution {
public:
     bool check(int k, int h, vector<int>&piles)
     {
        int total = 0;
        for(int i=0;i<piles.size();i++)
        {
            int temp = (piles[i]+k-1)/k;
            total+=temp;
        }
        return total<=h;
     }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=INT_MAX;
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(mid,h,piles))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};