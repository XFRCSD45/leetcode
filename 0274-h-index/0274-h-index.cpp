class Solution {
public:
    int hIndex(vector<int>& arr) {
        if(arr.size()==1 )
        {
            if(arr[0]==0)
            {
                return 0;
            }
            else
            {
                  return 1;
            }
        }
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int ans=-1e9;
        for(int i=0;i<n;i++)
        {  int temp=0;
           if(arr[i]>=(n-i))
           {
               temp=n-i;
           }
               ans=max(ans,temp);
        }
        return ans;
    }
};