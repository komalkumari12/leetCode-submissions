class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0 ;
        
        queue<TreeNode*> q;
        q.push(root) ;
        int count=1 ;
        
        while(!q.empty()){
            int size= q.size() ;
            
            for(int i=0; i<size ;i++){
                TreeNode* node=q.front() ;
                q.pop() ;
                
                if(node->left){
                    q.push(node->left) ;
                    count++ ;
                }
                if(node->right){
                    q.push(node->right) ;
                    count++ ;
                }
            }
        }
        
        return count ;
    }
};