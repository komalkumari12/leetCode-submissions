class Solution {
public:
    int maxFreq =0 ;
    int currFreq=0;
    int pre=INT_MIN ;
    vector<int> ans ;
    
    vector<int> findMode(TreeNode* root){
        inorder(root) ;
        return ans;
    }
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        
        inorder(root->left) ;
        
        if(pre== root->val) ++currFreq ;
        else{
            pre= root->val ;
            currFreq=1 ;
        }
        
        if(currFreq > maxFreq){
            maxFreq = currFreq ;
            ans.clear() ;
            ans.push_back(root->val) ;
        }
        else if(currFreq == maxFreq) ans.push_back(root->val) ;

        
        inorder(root->right) ;

    }
};