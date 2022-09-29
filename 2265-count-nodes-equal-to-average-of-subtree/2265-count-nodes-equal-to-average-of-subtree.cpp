class Solution {
public:
    int count =0 ;
    vector<int> solve(TreeNode* root){
        if(!root)
            return {0, 0} ;
        
        vector<int> subTree(2) ;
        
        vector<int> left = solve(root->left) ;
        vector<int> right = solve(root->right) ;
        
        int avg = (left[0] + right[0] + root->val) / (1 + left[1] + right[1]) ;
        
        if(avg == root->val)
            count++ ;
        
        subTree[0] = left[0] + right[0] + root->val ;
        subTree[1] = left[1] + right[1] +1 ;
        
        return subTree ;
    }
        
    int averageOfSubtree(TreeNode* root) {
        solve(root) ;
        return count ;
    }
};