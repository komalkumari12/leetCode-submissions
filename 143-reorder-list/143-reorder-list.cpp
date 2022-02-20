class Solution {
public:
    ListNode* rev(ListNode* head2){
        ListNode* prev=NULL ;
        ListNode* curr=NULL ;
        
        while(head2){
            curr=head2 ;
            head2=head2->next ;
            curr->next=prev;
            prev=curr ;
        }
        return prev ;
    }
        
    void reorderList(ListNode* head) {
        ListNode* slow =head ;
        ListNode* fast =head ;
        
        while(fast && fast->next){
            fast=fast->next->next ;
            slow=slow->next ;
        }
        
        ListNode* head2 =slow->next ;
        slow->next=NULL ;
        
        head2=rev(head2) ;
        
        ListNode* ptr =NULL ;
        
        while(head2){
            ptr=head->next ;
            head->next=head2 ;
            head=head->next ;
            head2=head2->next ;
            head->next=ptr ;
            head=head->next ;
        }    
    }
};