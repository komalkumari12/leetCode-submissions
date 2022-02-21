class LRUCache {
public:
    class node{
        public:
        int k;
        int v ;
        node* next ;
        node* prev ;
        
        node(int key, int value){
            k=key ;
            v=value ;
        }
    };
    
    node* head =new node(-1,-1) ;
    node* tail =new node(-1,-1) ;
    
    unordered_map<int,node*> mpp ;
    int cap ;
    
    LRUCache(int capacity) {
        cap=capacity ;
        head->next=tail ;
        tail->prev=head ;
    }
    
    void delNode(node* del){
        node* delprev= del->prev ;
        node* delnext= del->next ;
        
        delprev->next=delnext ;
        delnext->prev=delprev ;
    }
    
    void addNode(node* newNode){
        node* temp = head->next ;
        newNode->next=temp ;
        newNode->prev=head ;
        temp->prev=newNode ;
        head->next=newNode ;   
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            node* resNode=mpp[key] ;
            int res =resNode->v ;
            
            mpp.erase(key) ;
            delNode(resNode) ;
            addNode(resNode) ;
            
            mpp[key]=head->next ;
            return res ;
        }
        return -1 ;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            node* existingNode =mpp[key] ;
            mpp.erase(key) ;
            delNode(existingNode) ;
        }
        
        if(cap==mpp.size()){
            mpp.erase(tail->prev->k) ;
            delNode(tail->prev) ;
        }
        
        addNode(new node(key,value)) ;
        mpp[key]=head->next ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */