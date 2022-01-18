/*Approach
 for push:
  push elements into stack1
  
 for pop:
  if(stack2 is not empty)
   pop stop element of stack2
   
  else
  transfer all elements of stack1 into stack2
    if then 
    stack2 is empty:  Queue is empty
    stack2 is not empty: pop top element of stack2
    
*/    
    
class MyQueue {
public:
    stack<int> s1,s2 ;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x) ;
    }
    
    int pop() {
        if(empty()){
            cout<<" Queue is empty " ;
            return -1 ;
        }
        
        int ans;
        if(!s2.empty()){
            ans=s2.top() ;
            s2.pop() ;
        }
        
        else{
            while(!s1.empty()){
                s2.push(s1.top()) ;
                s1.pop() ;
            }
            
            if(!s2.empty()){
                ans=s2.top() ;
                s2.pop() ;
            }
            else
                ans=-1 ;
        }   
        return ans;
    }
    
    int peek() {
        if(empty()) return -1;
        if(!s2.empty()){
            return s2.top() ;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top()) ;
                s1.pop() ;
            }
            
            if(!s2.empty()){
                return s2.top() ;
            }   
            else
                return -1 ;
        }  
        return s2.top() ;
    }
    
    bool empty() {
      return s1.empty() && s2.empty();
        
    }
};

