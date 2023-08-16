class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
         vector<int>ans;
        int n=a.size();
        deque<int>dq;
        int i=0;
        for(i=0;i<k;i++)
        {
            while(!dq.empty() && (a[dq.back()]<=a[i]))
            dq.pop_back();
            
            dq.push_back(i);
        }
        for(;i<n;i++)
        {
            ans.push_back(a[dq.front()]);
            
            while(!dq.empty() && (dq.front()<=(i-k)))
            dq.pop_front();
            while(!dq.empty() && (a[dq.back()]<=a[i]))
            dq.pop_back();
             dq.push_back(i);
        }
        ans.push_back(a[dq.front()]);
        return ans;
    }
};