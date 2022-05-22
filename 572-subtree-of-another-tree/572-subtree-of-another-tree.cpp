class Solution {
public:
    bool check(TreeNode* root, TreeNode* sub){
        if(!root && !sub) return true ;
        
        if(!root || !sub || root->val != sub->val) return false ;
        
        return check(root->left, sub->left) && check(root->right, sub->right) ;
    }
        
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false ;
        
        if(root->val == subRoot->val)
            if(check(root,subRoot) == true)
                return true ;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) ;
        
    }
};