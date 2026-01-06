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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=INT_MIN, level=0, currLevel=1;
        q.push(root);
        while(!q.empty())
        {
            int len= q.size();
            int currSum=0;
            for(int i=0;i<len;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                currSum+=node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(currSum>ans)
                {
                    ans=currSum;
                    level=currLevel;
                }
                currLevel++;
        }
        return level;
    }
};