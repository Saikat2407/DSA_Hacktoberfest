/*
 problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

 104. Maximum Depth of Binary Tree


 Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
 */


 class Solution {
    public int maxDepth(TreeNode root) {
       return  heightOfTree(root);

    }

    public int heightOfTree(TreeNode root) 
    {
          if(root == null) {
              return 0;

          }

         int leftHeight =  heightOfTree(root.left);
         int rightHeight = heightOfTree(root.right);

         return Math.max(leftHeight, rightHeight) +1;
         
    }
}


