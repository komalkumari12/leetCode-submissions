class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans ;
        if(root==NULL) return ans ;
        
        queue<TreeNode*>q ;
        q.push(root) ;
        
        while(!q.empty()){
            int size=q.size() ;
            vector<int>row(size) ;
            
            for(int i=0; i<size ;i++){
                TreeNode* node=q.front() ;
                q.pop() ;
                
                row[i]=node->val ;
                if(node->left)
                    q.push(node->left) ;
                if(node->right)
                    q.push(node->right) ;
            }
            ans.push_back(row) ;
        }
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};