class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(-1) ;
        start->next = head ;
        ListNode* fast = start ;
        ListNode* slow = start ;
        
        for(int i=0; i<n ;i++) fast = fast->next ;
        
        while(fast->next != NULL){
            fast= fast->next ;
            slow=slow ->next ;
        }
        slow->next=slow->next->next ;
        
        return start->next ;
        }
};