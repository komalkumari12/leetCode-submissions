class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        
        //STEP 1: insert newNode in between of origional list
        Node* ptr = head;
        while(ptr){
            Node* newNode =new Node(ptr->val) ;
            
            newNode->next=ptr->next ;
            ptr->next=newNode ;
            ptr=newNode->next ;
        }
        
        //STEP 2: random pointer
        ptr=head ;
        while(ptr){
            if(ptr->next){
                ptr->next->random = ptr->random ? ptr->random->next : NULL ;
            }
            ptr=ptr->next->next ;
        }
        
        //STEP 3: segregate two linked lists
        Node* temp =head ;
        Node* ori= head ;
        Node* clone= head->next ;
        Node* result = head->next ;
        
        while(ori){
            ori->next=ori->next->next ;
            clone->next = clone->next ? clone->next->next : NULL ;
            
            ori=ori->next ;
            clone=clone->next ;
        }
        
        return result ;
    }
};