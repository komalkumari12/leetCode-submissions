class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)    return head ;
        
        ListNode *curr = head->next, *prev = head ;
        while(curr){
            if(curr->val == prev->val){
                prev->next = prev->next->next ;
            }
            else{
                prev = curr ;
            }
            
            curr= curr->next ;  
        }
        
        return head ;
    }
};