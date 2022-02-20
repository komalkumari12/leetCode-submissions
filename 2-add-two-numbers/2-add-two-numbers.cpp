class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy =new ListNode(0) ;
        ListNode* ptr = dummy ;
        int carry=0 ;
        
        while(l1 || l2 || carry){
            int sum=0; 
            
            if(l1){
                sum+=l1->val ;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val ;
                l2=l2->next;
            }
            sum+=carry ;
            carry=sum/10 ;
            
            ListNode* newNode =new ListNode(sum%10) ;
            ptr->next=newNode ;
            ptr=ptr->next ;
        }
        
        return dummy->next ;
    }
};



/*
    Approach 2
    But not working for all cases
    
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(0,l1) ;
        ListNode* ptr=dummy ;
        
        int carry= 0;
        
        while(l1 && l2){
            int sum = carry+ l1->val +l2->val ;
            if(sum>=10)
                carry=1;
            else carry=0;
            
            sum=sum%10 ;
            
            l1->val=sum ;
            ptr->next=l1 ;
            ptr=ptr->next ;
            
            l1=l1->next ;
            l2=l2->next ;
        }
        
        if(l2==NULL)
        while(l1!=NULL){
            int sum = carry+ l1->val;
            
            if(sum>=10)
                 carry=1;
             else carry=0;
            
            sum=sum%10 ;
            
            l1->val=sum ;
            
            ptr->next=l1 ;
            l1=l1->next ;
        }
        
        if(l1==NULL)
        while(l2){
            int sum = carry +l2->val ;
            
            if(sum>=10)
                carry=1;
            else carry=0;
            
            sum=sum%10 ;
            
            l2->val=sum ;
            
            ptr->next=l2 ;
            l2=l2->next ;
        }
        
        if(carry!=0){
            ListNode* temp= new ListNode(carry) ;
            ptr->next=temp ;
        }
        
        
        
        return dummy->next ;
    }
};

*/