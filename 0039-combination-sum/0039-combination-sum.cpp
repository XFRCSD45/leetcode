class Solution {
public:

void solve(vector<vector<int>>&ans, vector<int>&curr, int target, vector<int>candidates, int n, int pos, int sum)
{
    if(pos>=n || sum>target)
    {
        return ;
    }
    if(sum==target)
    {
        ans.push_back(curr);
        return;
    }

        curr.push_back(candidates[pos]);
        solve(ans,curr, target, candidates, n, pos, sum+candidates[pos]);
        curr.pop_back();
        solve(ans,curr, target, candidates, n, pos+1, sum);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int n = candidates.size();
        solve(ans,curr, target,candidates, n, 0,0);
        return ans;
    }
};