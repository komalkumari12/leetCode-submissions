/* Approach
     1. Every value in the tree has a range of minVal and a maxVal
     2. if value >= maxVal   OR   value <= minVal     =>indicates tree is not a BST
     3. check for every element in tree
*/

class Solution {
public:
    bool helper(TreeNode*root ,long minVal ,long maxVal){
        if(root == NULL)  return true ;
        if(root->val >= maxVal || root->val <= minVal)  return false ;
        
        return helper(root->left ,minVal ,root->val) && helper(root->right ,root->val ,maxVal) ;
            
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX) ;
    }
};