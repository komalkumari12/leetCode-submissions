class Solution {
    TreeNode* prev; 
public:
    void flatten(TreeNode* root){
        if(!root) return ;
        stack<TreeNode*> st ;
        st.push(root) ;
        
        while(!st.empty()){
            TreeNode* temp=st.top() ;
            st.pop() ;
            
            if(temp->right)
                st.push(temp->right) ;
            if(temp->left)
                st.push(temp->left) ;
            
            
            if(!st.empty())
                temp->right= st.top() ;
            
            temp->left = NULL ;
        }
    } 
};
