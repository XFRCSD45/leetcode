class Solution {
public:
    int maxArea(vector<int>& h) {
     int n = h.size();
     int i=0, j=n-1;
     int ans =0;
     while(i<j)
     {
        int temp = (j-i)*min(h[i], h[j]);
        ans = max(ans, temp);
        if(h[i]<h[j])
        {
            i++;
        }
        else{
            j--;
        }
     }   
     return ans;
    }
};