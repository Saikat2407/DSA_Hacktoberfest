//In this program we will traverse the tree in three ways
//1. Preorder   2. Inorder   3. Postorder
//Preorder: Root, Left, Right
//Inorder: Left, Root, Right
//Postorder: Left, Right, Root

/*   Preorder Traversal  
problem link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
     Given a binary tree, find its preorder traversal.

Example 1:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 
Example 2:

Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: 6 3 1 2 2 

Your Task:
You just have to complete the function preorder() which takes the root node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 104
0 <= Data of a node <= 105

 */

 
// steps to slove a problem
// 1. Create a arrayList and store all the root, left, right value in it.
// 2. calling recursively
class BinaryTree
{
    //Function to return a list containing the preorder traversal of the tree.
    static ArrayList<Integer> preorder(Node root)
    {
        // Code here
        ArrayList<Integer> al = new ArrayList<>();
        if(root != null) {
         al.add(root.data);
        al.addAll(preorder(root.left));
        al.addAll(preorder(root.right));
           
        }
        
       return al;
    }



/* Inorder Traversal */ 
// problem link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
/*
  Given a Binary Tree, find the In-Order Traversal of it.

Example 1:

Input:
       1
     /  \
    3    2
Output: 3 1 2

Example 2:

Input:
        10
     /      \ 
    20       30 
  /    \    /
 40    60  50
Output: 40 20 60 10 50 30

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrder() that takes root node of the tree as input and returns a list containing the In-Order Traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 105

 */


 
// inorder: left, root, right
class Solution {
    // Function to return a list containing the inorder traversal of the tree.
    ArrayList<Integer> inOrder(Node root) {
        // Code
    ArrayList<Integer> ans = new ArrayList<>();
       if(root!= null) {
           ans.addAll(inOrder(root.left));
           ans.add(root.data);
           ans.addAll(inOrder(root.right));
           
           }
           
           return ans;
    }
}


/*  Postorder Traversal

problem link: https://practice.geeksforgeeks.org/problems/postorder-traversal/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5


Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19
Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11

Your Task:
You don't need to read input or print anything. Your task is to complete the function postOrder() that takes root node as input and returns an array containing the postorder traversal of the given Binary Tree.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 106


 */

 // Post order: left, right, root.

class Tree
{
    //Function to return a list containing the postorder traversal of the tree.
    ArrayList<Integer> postOrder(Node root)
    {
       // Your code goes here
       ArrayList<Integer> ans = new ArrayList<>();
       
       if(root!= null) {
           ans.addAll(postOrder(root.left));
           ans.addAll(postOrder(root.right));
           ans.add(root.data);
       }
       return ans;
    }
}
