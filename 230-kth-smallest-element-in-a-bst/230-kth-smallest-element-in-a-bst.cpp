/* Approach
     1.Through inorder traversal, store every element in a vector (ans)
     2.kth smallest element will be ans[k-1]
*/

class Solution {
public:
    vector<int> ans ;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return  ;
        inorder(root->left) ;
        ans.push_back(root->val) ;
        inorder(root->right) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root) ;
        
        return ans[k-1] ;
    }
};