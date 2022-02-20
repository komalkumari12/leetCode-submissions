class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev =NULL ;
        ListNode* curr=NULL ;
        
        while(head){
            curr=head ;
            head=head->next ;
            curr->next =prev ;
            prev=curr ;
        }
        return prev ;
    }
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1) ;
        l2=rev(l2) ;
        ListNode* dummy= new ListNode(0) ;
        ListNode* ptr =dummy ;
        int carry=0;
        
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=l1->val ;
                l1=l1->next ;    
            }
            if(l2){
                sum+=l2->val ;
                l2=l2->next ;
            }
            sum+=carry ;
            carry=sum/10 ;
            
            ListNode* newNode =new ListNode(sum%10) ;
            ptr->next=newNode ;
            ptr=ptr->next ;
        }
        
        return rev(dummy->next) ;
    }
};