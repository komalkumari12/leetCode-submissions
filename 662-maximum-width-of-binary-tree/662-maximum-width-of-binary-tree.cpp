class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q ;
        q.push({root,0}) ;
        
        long ans =0;
        while(!q.empty()){
            int size=q.size() ;
            
            long left = q.front().second ;
            long right =q.back().second ;
            
            ans = max(ans,right-left+1) ;
            
            for(int i=0; i<size ;i++){
                long ind =q.front().second ;
                TreeNode* temp = q.front().first ;
                q.pop() ;
                
                if(temp->left)
                    q.push({temp->left, 2*ind+1}) ;
                if(temp->right)
                    q.push({temp->right, 2*ind+2}) ;
            }
        }
        return ans ;
    }
};