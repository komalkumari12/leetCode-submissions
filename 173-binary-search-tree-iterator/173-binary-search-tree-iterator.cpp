class BSTIterator {
public:
    stack<TreeNode*> st ;
    
    void inorder(TreeNode* root){
        
        while(root){
            st.push(root) ;
            root= root->left ;
        }
    }
        
    BSTIterator(TreeNode* root) {
        inorder(root) ;
    }
    
    int next() {
        TreeNode* node = st.top() ;
        st.pop() ;
        
        if(node->right)
            inorder(node->right) ;
        
        return node->val ;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true ;
    }
};
