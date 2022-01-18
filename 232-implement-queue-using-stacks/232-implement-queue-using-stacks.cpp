/* Approach
 step1: put elements of stack1 into stack2
 step2: push element to stack1
 step3: put elements of stack2 to stack1
 */

class MyQueue {
public:
    stack<int> s1,s2 ;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top()) ;
            s1.pop() ;
        }
        
        s1.push(x);
        
        while(!s2.empty()){
            s1.push(s2.top()) ;
            s2.pop() ;
        }
        
    }
    
    int pop() {
        if(empty()){
            cout<<" Queue is empty " ;
            return -1;
        }
        int ans=s1.top() ;
        s1.pop() ;
        
        return ans;
    }
    
    int peek() {
        if(empty()){
            cout<<" Queue is empty " ;
            return -1 ;
        }
        
        return s1.top() ;
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        else
            return false ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */