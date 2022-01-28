class Solution {
public:   
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)  return NULL ;
        if(!head->next){
            TreeNode* root = new TreeNode(head->val) ;
            return root ;
        } 
        
        ListNode* slow=head, *fast=head->next->next ;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next ;
            fast=fast->next->next ;
        }
        
        ListNode* temp=slow->next ;
        slow->next=NULL ;
        
        TreeNode* root=new TreeNode(temp->val) ;
        root->left=sortedListToBST(head) ;
        root->right=sortedListToBST(temp->next);
        
        return root ;
        
    }
};
