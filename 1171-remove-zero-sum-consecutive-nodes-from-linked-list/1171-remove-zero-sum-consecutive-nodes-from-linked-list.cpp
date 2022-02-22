class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL ;
        
        unordered_map<int,ListNode*> mpp ;
        ListNode* dummy = new ListNode(0) ;
        dummy->next = head ;
        int prefixSum=0 ;
        
        mpp[prefixSum]=dummy ;
        
        while(head){
            prefixSum+=head->val ;
            mpp[prefixSum]= head ;
            head=head->next ;
        }
        
        head=dummy;
        prefixSum=0;
        
        while(head){
            prefixSum+=head->val ;
            ListNode* temp = mpp[prefixSum] ;
            
            if(head != temp)
                head->next = temp->next;
            
            head=head->next ;
        }
        
        return dummy->next ;
    }
};
