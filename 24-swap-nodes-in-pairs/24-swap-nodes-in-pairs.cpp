class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head ;
        
        ListNode* ptr =new ListNode(0) ;
        ListNode* prev=ptr ,*curr=head ;
        
        while(curr && curr->next){
            ListNode* next ,*nextPair ;
            next= curr->next ;
            nextPair= curr->next->next ;
            
            next->next=curr ;
            curr->next = nextPair ;
            prev->next = next ;
            
            prev = curr ;
            curr = nextPair ;
        }
        return ptr->next ;
        
    }
};