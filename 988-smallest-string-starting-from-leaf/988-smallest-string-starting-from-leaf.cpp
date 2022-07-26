class Solution {
public:
    void find(TreeNode* root, string str, string &ans){
        if(!root) return  ;
        
        if(!root->left && !root->right){
            str+= char(root->val + 'a') ;
            reverse(str.begin(), str.end()) ;
            
            if(ans == "")
                ans = str ;
            else
                ans = min(str, ans) ;
            return  ;
        } 
        
        // str+= to_string(root->val + 65) ;
        str+= char(root->val + 'a') ;
        
        find(root->left, str, ans) ;
        find(root->right, str, ans) ;
    }
        
    string smallestFromLeaf(TreeNode* root) {
        string str, ans ;
        find(root, str, ans) ;
        
        return ans ;
    }
};