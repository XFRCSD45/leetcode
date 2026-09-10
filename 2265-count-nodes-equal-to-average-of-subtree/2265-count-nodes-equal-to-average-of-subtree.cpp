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
int count=0;
pair<int, int> solve(TreeNode* root)
{
    if(root == NULL)
    {
        return {0,0};
    }
    pair<int,int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);
    int total = root->val + leftAns.second + rightAns.second;
    int noOfNodes = 1 + leftAns.first + rightAns.first;
    int avg = total/noOfNodes;
    if(avg == root->val)
    {
        // cout<<root->val<<endl;
        count++;
    } 
    return {noOfNodes, total};
}
    int averageOfSubtree(TreeNode* root) {
        pair<int,int>p = solve(root);
        return count;

    }
};