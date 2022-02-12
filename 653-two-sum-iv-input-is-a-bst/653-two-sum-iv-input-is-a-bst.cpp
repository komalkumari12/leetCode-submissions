class Solution {
private: 
    unordered_set<int> set ;
public:
    bool findTarget(TreeNode* root, int target ) {
        if(!root) return false ;
        
        if(set.find(target - root->val) != set.end()) return true ;
        set.insert(root->val) ;
        
        return findTarget(root->left ,target) ||  findTarget(root->right ,target) ;
    }
};
        