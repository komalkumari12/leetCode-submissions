class Solution {
public:
    string solve(TreeNode* root){
        string ans = to_string(root->val) ;
        
        if(root->left){
            ans += "(" + solve(root->left) + ")" ;
        }
        if(root->right){
            if(!root->left)  ans += "()" ;
            ans += "(" + solve(root->right) + ")" ;
        }
        
        return ans ;
    }
        
    string tree2str(TreeNode* root) {
        return solve(root) ; 
    }
};