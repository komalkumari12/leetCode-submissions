class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root) ;
        stack<int> st ;
        int level =0 ;
        
        while(!q.empty()){
            int size = q.size() ;
            
            for(int i=0; i<size; i++){
                TreeNode* node= q.front() ;
                q.pop() ;
                
                if(level%2 == 0){
                    //EVEN Level
                    if(node->left)   st.push(node->left->val) ;
                    if(node->right)   st.push(node->right->val) ;
                }
                else{
                    //ODD level
                    node->val = st.top() ;
                    st.pop() ;
                }
                    
                if(node->left)   q.push(node->left) ;
                if(node->right)   q.push(node->right) ;
            }
            
            level++ ;
        }   
            
        return root ;
    }
};