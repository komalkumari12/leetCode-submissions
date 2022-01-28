/* Approach
    1. store values of node in a vector in ascending order through inorder
    2. find 2 sum in a vector
*/    

class Solution {
public:
    vector<int> ans ;
    
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        
        inorder(root->left) ;
        ans.push_back(root->val) ;
        inorder(root->right) ;
    }
    
    bool findTarget(TreeNode* root, int key) {
        inorder(root) ;      
        
        int i=0, j=ans.size() -1 ;
        
        while(i<j){
            if(ans[i] + ans[j]== key)
                return true ;
            else if(ans[i] + ans[j] > key)
                j-- ;
            else if(ans[i] + ans[j] < key)
                i++ ;
        }
        return false ;
    }
};

/*
note: j should be strictly greater than than i while traversing the vector
          tree-[1] ,key-2 ......in this case (ans[i] + ans[j]==2) which gives true 
*/          