
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL  || head->next->next==NULL)
             return head ;
            
        ListNode* oddHead=head ,* evenHead=head->next ;
        ListNode* odd=oddHead ,*even=evenHead ;
        
        while(even!=NULL && even->next!=NULL ){
            odd->next=odd->next->next ;
            even->next=even->next->next ;
            odd=odd->next ;
            even=even->next ;
        }
        odd->next=evenHead ;
        
        return oddHead ;
    }
} ;