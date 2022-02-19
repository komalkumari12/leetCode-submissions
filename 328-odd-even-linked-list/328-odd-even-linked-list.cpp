class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head ;
        
        ListNode* odd =head ;
        ListNode* even=head->next ;
        ListNode* evenFirst=even ;
        
        while(1){
            if(!even->next){
                odd->next = evenFirst ;
                break ;
            }
            odd->next = even->next ;
            odd = odd->next ;
            
            if(!odd->next){
                even->next = odd->next ;
                odd->next = evenFirst ;
                break ;
            }
            
            even->next = odd->next ;
            even = even->next ;
        }
        return head ;
    }
};