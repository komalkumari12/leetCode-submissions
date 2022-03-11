class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
		return NULL;
    ListNode* currentNode = head;
    ListNode* tailFinder = head;
        
    int count = 0;
    while(count<k){
    	count++;
    	if(tailFinder->next != NULL){
    		tailFinder = tailFinder->next;
   		}
   		else{
   			tailFinder = head;
   			k = k%count;
    		count = 0;
   		}
    }
    while(tailFinder->next!=NULL && currentNode->next != NULL){
    	currentNode = currentNode->next;
    	tailFinder = tailFinder->next;
    }
    if(currentNode == tailFinder){
    	return head;
    }
    ListNode* newHead = currentNode->next;
    currentNode->next = NULL;
    tailFinder->next = head;
    return newHead;
    }
};
