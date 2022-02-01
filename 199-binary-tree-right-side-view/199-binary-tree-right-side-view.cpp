/*  Approach
      1. reverse preOrder  root, right, left
      2.if its the first element in the level insert into right view vector
      3.how to check that....... if size of right view vector is equal to the level
*/

class Solution {
public:
    void rightSideViewHelper(TreeNode*root, int level ,vector<int>&right_view ){
        if(root==NULL) return ;
        if(right_view.size() == level)
            right_view.push_back(root->val) ;
        
        rightSideViewHelper(root->right, level+1, right_view) ;
        rightSideViewHelper(root->left, level+1, right_view) ;    
    }
        
    vector<int> rightSideView(TreeNode* root) {
        vector<int>right_view ;
        
        rightSideViewHelper(root, 0, right_view) ;
        
        return right_view ;
    }
};