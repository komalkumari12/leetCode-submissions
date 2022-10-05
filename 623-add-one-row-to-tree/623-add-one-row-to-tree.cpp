class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && depth > 2){
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL){
                    q.push(top->left);
                }
                
                if(top->right != NULL){
                    q.push(top->right);
                }
            }
            
            depth--;
        }
        
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            
            newLeft->left = top->left;
            newRight->right = top->right;
            
            top->left = newLeft;
            top->right = newRight;
        }
        
        return root;
    }
};