class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL; 
        
        ListNode *slow =head ;
        ListNode *fast =head ;
        ListNode *count =head ;
        
        while(fast && fast->next){
            fast=fast->next->next ;
            slow=slow->next ;
            
            if(slow == fast){
                while(count != slow ){
                    count=count->next ;
                    slow=slow->next ;
                }
                return count ;
            }
        }
        return NULL ;
    }
};