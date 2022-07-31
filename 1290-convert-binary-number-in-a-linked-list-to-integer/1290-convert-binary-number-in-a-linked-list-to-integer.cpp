class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len =0;
        ListNode* ptr = head ;
        
        while(ptr){
            len++ ;
            ptr = ptr->next ;
        }
        
        ptr = head ;
        int ans =0 ;
        while(ptr){
            ans += pow(2, len-1) * ptr->val ;
            ptr= ptr->next ;
            len = len-1 ;
        }
        
        return ans ;
    }
};