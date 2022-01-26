/* Appproach
     1. For root->left upper bound will be root->val 
     2. For root->right upper bound will be INT_MAX only
*/

class Solution {
public:
    TreeNode* helper(vector<int>ans , int &i ,int upper_bound){
        if(i==ans.size() || ans[i]> upper_bound) return NULL ;
        
        TreeNode* root=new TreeNode(ans[i++]) ;
        
        root->left=helper(ans, i , root->val) ;
        root->right=helper(ans, i , upper_bound) ;
        
        return root ;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0; 
        return helper(pre ,i ,INT_MAX) ;
    }
};