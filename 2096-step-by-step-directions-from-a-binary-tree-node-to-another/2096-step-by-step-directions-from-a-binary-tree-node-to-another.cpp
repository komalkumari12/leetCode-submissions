class Solution {
public:
    TreeNode* findLca(TreeNode* root, int p, int q){
        if(!root || root->val == p || root->val == q) return root ;
        
        TreeNode* left = findLca(root->left, p, q) ;
        TreeNode* right = findLca(root->right, p, q) ;
        
        if(!left && !right) return NULL ;
        if(!left) return right ;
        if(!right) return left ;
        
        return root ;
    }
        
    bool findPath(TreeNode* lca, int node, string& str){
        if(!lca) return false ;
        if(lca->val == node) return true ;
        
        bool find1 =findPath(lca->left, node, str+='L') ;
        if(find1) return true ;
        str.pop_back() ;
        
        bool find2 =findPath(lca->right, node, str+='R') ;
        if(find2) return true ;
        str.pop_back() ;
        
        return false ;
    }
        
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca =findLca(root, startValue, destValue) ;
        
        string sPath ,dPath ;
        findPath(lca, startValue, sPath) ;
        findPath(lca, destValue, dPath) ;
        
        for(int i=0; i<sPath.size(); i++){
            sPath[i] ='U' ;
        }
        
        return sPath+dPath ;
    }
};