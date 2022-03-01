class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sumofLevel ;
        queue<TreeNode*> q;
        q.push(root) ;
        
        while(!q.empty()){
            int size= q.size() ;
            int sum=0 ;
            
            for(int i=0; i<size ;i++){
                TreeNode* node= q.front() ;
                q.pop() ;
                
                if(node->left)
                    q.push(node->left) ;
                if(node->right)
                    q.push(node->right) ;
                
                sum+=node->val ;
            }
            sumofLevel.push_back(sum) ;
        }
        
        int maxLevel =-1;
        int maxSum=INT_MIN ;
        
        for(int i=0; i<sumofLevel.size() ;i++){
            if(maxSum < sumofLevel[i]){
                maxSum = sumofLevel[i] ;
                maxLevel = i ;
            }
        }
        
        return maxLevel+1 ;
    }
};