class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL ;
        
        ListNode* slow = head ;
        ListNode* fast =head ;
        ListNode* entry =head;
            
        while(fast->next && fast->next->next){
            slow=slow->next ;
            fast=fast->next->next ;
            
            if(slow==fast){
                while(entry != slow){
                    entry =entry->next ;
                    slow= slow->next ;
                }
                return entry ;
            }  
        }
        return NULL ;
    }
};