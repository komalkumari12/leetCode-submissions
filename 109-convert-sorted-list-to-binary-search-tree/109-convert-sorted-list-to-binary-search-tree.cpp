/*  Approach
  Converting linked list problem into vector problem
  
  1. storing list in vector
  2. applying binary search on vector and creating linked list
*/  

class Solution {
public:
    TreeNode* build(vector<int>& nums ,int start, int end){
        if(start <= end){
            int mid =start + (end-start)/2 ;
            
            TreeNode* root= new TreeNode(nums[mid]) ;
            root->left =build(nums, start, mid-1) ;
            root->right =build(nums, mid+1, end) ;
            return root;
        }
        return NULL ;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        
        while(head!=NULL){
            nums.push_back(head->val) ;
            head=head->next ;
        }
        
        return build(nums, 0, nums.size()-1) ;
        
    }
};