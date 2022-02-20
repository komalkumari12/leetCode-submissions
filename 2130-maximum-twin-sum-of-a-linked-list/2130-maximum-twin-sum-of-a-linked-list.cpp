class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head ;
        ListNode* fast=head ;
        
        //find mid
        while(fast && fast->next){
            fast=fast->next->next ;
            slow=slow->next ;
        }
        
        //reverse linked list 2 ... head as l2
        ListNode* l2=NULL ;
        ListNode* curr=NULL ;
        
        while(slow){
            curr=slow ;
            slow=slow->next ;
            curr->next=l2 ;
            l2=curr ;
        }
        
        //find maxValue 
        int maxValue= INT_MIN ;
        while(l2){
            maxValue=max(maxValue ,head->val + l2->val) ;
            head=head->next ;
            l2=l2->next ;
        }
        
        return maxValue ;
    }
};