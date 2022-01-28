class Solution {
public:
    TreeNode* Helper(vector<int>& nums ,int start, int end){
        if(start<=end){
            int mid =start+(end-start)/2 ;
            
            TreeNode* root= new TreeNode(nums[mid]) ;
            root->left=Helper(nums, start, mid-1) ;
            root->right=Helper(nums, mid+1, end) ;
            
            return root ;

        }
        return NULL ;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return Helper(nums,0, nums.size()-1) ;
    }
};