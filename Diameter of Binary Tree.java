 public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
class Solution {
	int max;
    public int diameterOfBinaryTree(TreeNode root) {
    	max=0;
        if (root==null) {
			return 0;
		}
        getLength(root);
        return max-1; //求路径长度 节点数-1
    }
    public int getLength(TreeNode root) {
		if (root==null) {
			return 0;
		}else {
			int left=getLength(root.left);
			int right=getLength(root.right);
			max=Math.max(max,left+right+1 ); //用于比较是否不穿过根节点时大的情况 穿过根节点时 根节点的子节点只取 left right最大的一个 
			return 1+Math.max(left, right);  //比较不穿过的情况下left直接+right+1
		}
	}
}