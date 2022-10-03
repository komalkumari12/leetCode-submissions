class FindElements {
public:
    set<int> st ;
    void recoverTree(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root) ;
        
        while(!q.empty()){
            int size = q.size() ;
            
            for(int i=0; i<size; i++){
                TreeNode* node= q.front() ;
                q.pop() ;
                st.insert(node->val) ;
                
                if(node->left){
                    node->left->val = 2*(node->val) + 1; 
                    q.push(node->left) ;
                }
                if(node->right){
                    node->right->val = 2*(node->val) + 2; 
                    q.push(node->right) ;
                }
            }
        }
    }
        
    FindElements(TreeNode* root) {
        root->val = 0 ;
        recoverTree(root) ;
    }
    
    bool find(int target) {
        if(st.find(target) != st.end())
            return true ; 
            
        return false ;
    }
};