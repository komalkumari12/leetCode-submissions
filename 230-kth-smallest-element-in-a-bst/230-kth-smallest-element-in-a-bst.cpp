/* Approach
     1.Through postorder traversal, store every element in a vector (ans)
     2.sort the elements in vector in ascending order
     3.kth smallest element will be ans[k-1]
*/

class Solution {
public:
    vector<int> ans ;
    
    void postorder(TreeNode* root){
        if(root==NULL)
            return ;

        postorder(root->left) ;
        postorder(root->right) ;
        ans.push_back(root->val) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        postorder(root) ;
        
        sort(ans.begin() , ans.end()) ;
        
        return ans[k-1] ;
    }
};

