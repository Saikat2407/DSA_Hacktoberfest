class Solution {
public:
    bool havingPathSum(TreeNode* root, int targetSum , int pres_sum) {
         if(root==NULL){
            return false; 
        }
        pres_sum+=root->val; 
        if(root->left == NULL and root->right == NULL){
            return pres_sum == targetSum; 
        }
        return havingPathSum(root->left,targetSum,pres_sum) || havingPathSum(root->right,targetSum,pres_sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return havingPathSum(root,targetSum,0); 
        
    }
};
