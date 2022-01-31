class Solution {
public:
    int helper(TreeNode*root,int& maxi){
        if(root==NULL) return 0 ;
        
        int l_sum=helper(root->left, maxi) ;
        if(l_sum <0) l_sum=0; 
        int r_sum=helper(root->right,maxi) ;
        if(r_sum <0) r_sum=0; 
        
        maxi=max(maxi ,root->val+r_sum+l_sum) ;
        
        return root->val + max(l_sum,r_sum) ;
    }
        
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN ;
        helper(root,maxi) ;
        
        return maxi ;
    }
};