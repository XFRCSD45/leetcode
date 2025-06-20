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
    int solve(int num, TreeNode* node)
    {
        if(node->left ==NULL && node->right ==NULL)
        {
            return num*10+node->val;
        }
        int leftAns=0;
        int rightAns=0;
        if(node->left)
        {
            leftAns = solve(num*10 + node->val, node->left);
        }
        if(node->right)
        {
            rightAns = solve(num*10 + node->val, node->right);
        }
        return leftAns + rightAns;
    }
    int sumNumbers(TreeNode* root) {
        return solve(0,root);
    }
};