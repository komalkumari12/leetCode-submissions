
/* Approach
     1. find the node where root->val == key
     2. find left max of that root 
     3. connect left max to right child of root
     4. connect parent node of root which is equal to key to left child of root
*/


class Solution {
public:
    TreeNode* findLeftMaxChild(TreeNode* root){
        if(root->right==NULL)
            return root ;
        
        return findLeftMaxChild(root->right) ;
    }
    
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL)
            return root->right ;
        if(root->right==NULL)
            return root->left ;
        
        TreeNode* rightChild= root->right ;
        TreeNode* leftMaxChild= findLeftMaxChild(root->left) ;
        
        leftMaxChild->right=rightChild ;
        return root->left ;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root==NULL)
            return NULL ;
        if(root->val == key)
            return helper(root) ;
        
        TreeNode*dummy= root ;
        
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left= helper(root->left) ;
                    break ;
                }
                else{
                    root=root->left ;
                }
            }
            
            else if(root->val < key){
                if(root->right && root->right->val == key){
                    root->right=helper(root->right) ;
                    break ;
                }
                else{
                    root=root->right ;
                }
            }
        }
        
        return dummy ;
    }
} ;

