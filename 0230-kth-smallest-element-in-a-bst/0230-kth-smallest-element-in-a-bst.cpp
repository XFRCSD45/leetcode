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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, ans = 0;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node)
                return;
            inorder(node->left);
            if (++count == k)
               { ans = node->val;
               return;}
            inorder(node->right);
        };
        inorder(root);
        return ans;
    }
};