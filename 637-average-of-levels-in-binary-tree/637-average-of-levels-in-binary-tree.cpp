class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans ;
        
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            int size = q.size() ;
            double avg =0 ;
            
            for(int i=0; i<size; i++){
                TreeNode* node = q.front() ;
                q.pop() ;
                
                avg += node->val ;
                
                if(node->left)  q.push(node->left) ;
                if(node->right) q.push(node->right) ;
            }
            
            avg = avg/size ;
            ans.push_back(avg) ;
        }
        
        return ans ;
    }
};