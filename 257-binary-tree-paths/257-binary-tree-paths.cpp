class Solution {
public:
    void Paths(TreeNode* root, string str, vector<string>& ans){
        if(!root) return ;
        if(!root->left && !root->right){
            str+= to_string(root->val) ;
            ans.push_back(str) ;
        }
        
        str+= to_string(root->val) + "->";
        
        Paths(root->left, str, ans) ;
        
        Paths(root->right, str, ans) ;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ;
        string str ; 
        Paths(root, str, ans) ;
        
        return ans ;
    }
};