/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
class Solution {
    public int maxDepth(TreeNode root) {
    	if (root==null) {
			return 0;
		}
    	int depth=1;
        if (root.left==null&&root.right==null) {
			return depth;
		}else {
			depth=Math.max(maxDepth(root.left),maxDepth(root.right) )+1;
		}
        return depth;
    }
}