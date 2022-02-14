class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL ;
        ListNode* curr= head ;
        
        while(curr){
            head= head->next ;
            curr->next= prev ;;
            prev =curr;
            curr=head ;
        }
        return prev ;
    }
};