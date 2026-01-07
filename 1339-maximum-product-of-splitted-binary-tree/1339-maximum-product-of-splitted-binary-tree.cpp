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
int mod = 1000000007;
int totalSum =0;
long long ans=0;
    long long findSum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        long long leftSum = findSum(root->left);
        long long rightSum = findSum(root->right);
        long long total = ((leftSum + rightSum) + root->val);
        return total;
    }
    long long solve(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        long long leftSum = solve(root->left);
        long long rightSum = solve(root->right);
        long long op1= ((totalSum-leftSum)*1LL*leftSum);
        long long op2 = ((totalSum-rightSum)*1LL*rightSum);
        ans=max(ans,max(op1,op2));
        long long total = ((leftSum + rightSum) + root->val);
        return total;
    }
    int maxProduct(TreeNode* root) {
    totalSum = findSum(root);
    solve(root);
    return (int)(ans%mod);   
    }
};