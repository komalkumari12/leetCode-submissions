class Solution {
public:
    TreeNode* buildTree(vector<int>&post, int postS ,int postE , vector<int>&in, int inS, int inE ,map<int, int>&inMap){
        if(inS>inE || postS > postE)  return NULL ;
        
        TreeNode* root= new TreeNode(post[postE]) ;
        int inRoot=inMap [root->val] ;
        int numsLeft=inRoot- inS ;
        
        root->left= buildTree(post ,postS , postS+numsLeft-1 , in ,inS ,inRoot-1 , inMap) ;
        root->right=buildTree(post ,postS+numsLeft ,postE-1 ,in , inRoot+1 ,inE ,inMap) ;
        
        return root ;
    }
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap ;
        for(int i= 0; i<inorder.size() ; i++)
            inMap[inorder[i]] = i ;
        
        return buildTree(postorder, 0, postorder.size()-1 ,inorder,0, inorder.size()-1 ,inMap) ;
    }
};