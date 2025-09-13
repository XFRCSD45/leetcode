/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public int solve(TreeNode root, int maxi)
    {
        if(root == null)
        {
            return 0;
        }
        int ans = 0;
        if(maxi <= root.val)
        {
            ans = 1 ;
        }
        maxi = Math.max(maxi, root.val);
        int left = solve(root.left, maxi);
        int right = solve(root.right, maxi);
        return ans+left+right;
    }
    public int goodNodes(TreeNode root) {
        
        int maxi = Integer.MIN_VALUE;
        int ans = solve(root, maxi );
        return ans;
    }
}