/* Approach
     1.Through preorder traversal, store every element in a vector (ans)
     2.sort the elements in vector in ascending order
     3.kth smallest element will be ans[k-1]
*/

class Solution {
public:
    vector<int> ans ;
    
    void preorder(TreeNode* root){
        if(root==NULL)
            return ;
        
        ans.push_back(root->val) ;
        preorder(root->left) ;
        preorder(root->right) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        preorder(root) ;
        
        sort(ans.begin() , ans.end()) ;
        
        return ans[k-1] ;
    }
};

