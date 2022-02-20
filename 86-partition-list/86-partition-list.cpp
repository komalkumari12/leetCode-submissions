class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* part1 =new ListNode(0) ;
        ListNode* part2 =new ListNode(0) ;
        ListNode* l1 =part1 ,*l2=part2 ;
        
        while(head){
            if(head->val < x){
                l1->next=head ;
                l1=l1->next ;  
            }
            else if(head->val >= x){
                l2->next=head ;
                l2=l2->next ;
            }
            head=head->next ;
        }
        l2->next=NULL ;
        l1->next=part2->next ;
        
        
        return part1->next ;
    }
};

