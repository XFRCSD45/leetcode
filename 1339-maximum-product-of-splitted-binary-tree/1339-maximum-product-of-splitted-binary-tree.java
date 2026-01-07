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
    private long sum(TreeNode node)
    {
        if(node == null)
        {
            return 0;
        }
        node.val +=sum(node.left) + sum(node.right);
        return node.val;
    }
    public int maxProduct(TreeNode root) {
        long totalSum = sum(root);
        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        long ans =0;
        long MOD = 1000000007L;
        while(!q.isEmpty())
        {
            TreeNode node = q.poll();
            if(node == null)
            {
                continue;
            }
            long res = (totalSum - node.val)*node.val;
            ans = Math.max(ans, res);
            System.out.println(node.val);
           if (node.left != null) q.add(node.left);
           if (node.right != null) q.add(node.right);
        }
        return (int)(ans % MOD);
    }
}