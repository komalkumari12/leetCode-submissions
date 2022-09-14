
class Solution {
public:
    int ans =0 ;
    bool check(vector<int>& freq){
        bool odd = false ;
        
        for(int i=0; i<freq.size(); i++){
            if(freq[i]%2 != 0){
                if(!odd)
                    odd= true ;
                else
                    return false ;
            }
        }
        
        return true ;
    }
        
    void solve(TreeNode* root, vector<int>& freq){
        if(!root)   return ;
        
        if(!root->left && !root->right){
            freq[root->val]++ ;
            
            if(check(freq))
                ans++ ;
            
            freq[root->val]-- ;
            return  ;
        }   
        
        freq[root->val]++ ;
        
        solve(root->left, freq) ;
        solve(root->right, freq) ;
        
        freq[root->val]-- ;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0) ;
        solve(root, freq) ;
        
        return ans ;
    }
};