class Solution {
public:
    void find(TreeNode* root, int tar, vector<int>& ds, int& count){
        if(!root) return ;
        
        ds.push_back(root->val) ;
        
        find(root->left, tar, ds, count) ;
        find(root->right, tar, ds, count) ;
        
        long sum =0;
        for(int i=ds.size()-1; i>=0; i--){
            sum += ds[i] ;
            if(sum == tar){
                count++ ;
            }
        }
        
        ds.pop_back() ;
    }
        
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> ds ;
        int count =0;
        find(root, targetSum, ds, count) ;
        return count ;
    }
};