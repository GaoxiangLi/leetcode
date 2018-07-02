  public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }
  //Binary Search Tree (BST) 左节点小于右节点 所以只需要统计rightsum（右边节点的和即可） 且用深度优先遍历 先右再中后左 
    class Solution {
        public TreeNode convertBST(TreeNode root) {
        	int[] rightSum = new int[1];//不能用全局变量 每一次dfs目标范围不同
            dfsHelper(root, rightSum);  
            return root;
        }
        public void dfsHelper(TreeNode root, int[] rightSum) {//先右再中后左
            if (root == null) return;		
            dfsHelper(root.right, rightSum); //先右
            root.val += rightSum[0]; //rightsum累加结果加到中间的root
            rightSum[0] = root.val;
            dfsHelper(root.left, rightSum);//再加到左边
        }
    }
    //主要考察bst性质