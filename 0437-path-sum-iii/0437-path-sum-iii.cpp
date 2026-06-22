/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int dfs(TreeNode* node, long long cur, long long target,
        unordered_map<long long, int>& mp) {
    if (!node) return 0;
    cur += node->val;
    int count = mp[cur - target];
    mp[cur]++;
    count += dfs(node->left, cur, target, mp);
    count += dfs(node->right, cur, target, mp);
    mp[cur]--; 
    return count;
}
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0]=1;
        return dfs(root, 0, targetSum, mp);
    }
};