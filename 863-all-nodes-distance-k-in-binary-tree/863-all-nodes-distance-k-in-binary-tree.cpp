class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mpp){
        queue<TreeNode*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            // int size = q.size() ;
            // q.pop() ;
            
            // for(int i=0; i<size; i++){
                TreeNode* node =q.front() ;
                q.pop() ;
                
                if(node->left){
                    mpp[node->left] =node ;
                    q.push(node->left) ;
                }
                if(node->right){
                    mpp[node->right] =node ;
                    q.push(node->right) ;
                }
            // }
        }
    }
        
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp ;       // node, parent
        
        markParents(root, mpp) ;
        
        queue<TreeNode*> q;
        q.push(target) ;
        int count=0 ; 
        // set<TreeNode*> vis ;
        // vis.insert(target) ;
        unordered_map<TreeNode*, bool> vis ;
        vis[target] = true ;
        
        while(!q.empty()){
            int size = q.size() ;
            if(count++ == k)    break ;
            
            for(int i=0; i<size; i++){
                TreeNode* node =q.front() ;
                q.pop() ;
                
                if(node->left && !vis[node->left]){
                    vis[node->left] = true ;
                    q.push(node->left) ;
                }
                if(node->right && !vis[node->right]){
                    vis[node->right] = true ;
                    q.push(node->right) ;
                }
                if(mpp[node] && !vis[mpp[node]]){
                    vis[mpp[node]] = true ;
                    q.push(mpp[node]) ;
                }
            }
        }
        
        vector<int> ans ;
        while(!q.empty()){
            ans.push_back(q.front()->val) ;
            q.pop() ;
        }
        
        return ans ;
    }
};