class MinStack {
public:
    stack<pair<int,int>> st ;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val}) ;
        }
        else{
            int minEle = st.top().second ;  //-2
            
            if(minEle < val){
                st.push({val, minEle}) ;
            }
            else{
                st.push({val, val}) ;
            }
        }
    }
    
    void pop() {
        st.pop() ;
    }
    
    int top() {
        return st.top().first ;
    }
    
    int getMin() {
        return st.top().second ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */