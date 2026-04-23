class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long>>m;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            long long last = 0;
            long long currSize=m[nums[i]].size();
            if(currSize!=0)
            {
                last = m[nums[i]][currSize-1];
            }
            m[nums[i]].push_back(last+i);
        }
        vector<long long>ans(n,0);
        unordered_map<int,int>traversal;
        for(int i=0;i<n;i++)
        {
           
            if(m[nums[i]].size()==1)
            {
                ans[i]=0;
            }
            else
            {
                vector<long long>&temp = m[nums[i]];
                int pos = traversal[nums[i]];
                ans[i]= 0LL+ (temp[temp.size()-1]-temp[pos]) - (1LL*i*( temp.size()-pos-1)) + ( 1LL*(pos+1)*i - temp[pos]); 
            }
             traversal[nums[i]]++;
        }
        return ans;
    }
};