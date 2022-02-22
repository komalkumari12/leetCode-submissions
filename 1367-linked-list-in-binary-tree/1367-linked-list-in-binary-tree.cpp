class Solution {
public:
    bool check(ListNode* head, TreeNode* root){
        if(!head) return true ;
        if(!root) return false ;
        
        if(root->val == head->val)
            return check(head->next, root->left) || check(head->next ,root->right) ;
        else
            return false ;
    }
        
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false ;
        
        return check(head ,root) || isSubPath(head, root->left) || isSubPath(head, root->right) ;
    }
};

