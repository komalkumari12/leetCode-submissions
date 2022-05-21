//TC: O(1)
//SC: O(n)

class BSTIterator {
public:
    vector<int> in ;
    int top =0 ;
    
    BSTIterator(TreeNode* root) {
        inorder(root) ;
    }
    
    void inorder(TreeNode* root){
        if(!root) return  ;
        
        inorder(root->left) ;
        in.push_back(root->val) ;
        inorder(root->right) ;
    }
        
    int next() {
        return in[top++] ;
    }
    
    bool hasNext() {
        if(top < in.size())
            return true;
        return false ;
    }
};