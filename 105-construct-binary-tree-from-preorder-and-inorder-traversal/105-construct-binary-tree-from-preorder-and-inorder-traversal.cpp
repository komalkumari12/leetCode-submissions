class Solution {
public:
    TreeNode* help(vector<int>&pre , int preS ,int preE ,vector<int>&in , int inS ,int inE ,map<int,int>&inMap){
        if( preS > preE  ||  inS > inE)  return NULL ;
        
        TreeNode* root= new TreeNode(pre[preS]) ;
        int inRoot =inMap[root->val] ;
        int numsLeft = inRoot - inS ;
        
        root->left =help(pre , preS+1 , preS + numsLeft , in ,inS ,inRoot - 1 ,inMap) ;
        root->right =help(pre ,preS + numsLeft +1 ,preE ,in, inRoot+ 1 ,inE ,inMap) ;
        
        return root ;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode* root = help(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};
