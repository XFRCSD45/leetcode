/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int>& pre, int lo = INT_MIN,
                              int hi = INT_MAX) {
        if (idx == pre.size() || pre[idx] < lo || pre[idx] > hi)
            return nullptr;
        TreeNode* node = new TreeNode(pre[idx++]);
        node->left = bstFromPreorder(pre, lo, node->val);
        node->right = bstFromPreorder(pre, node->val, hi);
        return node;
    }
};