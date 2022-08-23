class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* curr= head, *ptr= NULL ;
        
        while(head){
            curr = head ;
            head=head->next ;
            curr->next = ptr ;
            ptr = curr ;
        }
        
        return ptr ;
    }
        
    bool isPalindrome(ListNode* head) {
        // find middle
        // reverse second half
        // check for palindrome

        ListNode* fast = head, *slow = head ;
        while(fast && fast->next){
            fast = fast->next->next ;
            slow = slow->next ;
        }
        
        slow = reverseList(slow) ;
        
        while(slow != NULL){
            if(slow->val != head->val)  return false ;
            slow= slow->next ;
            head= head->next ;
        }
        
        return true ;
    }
};