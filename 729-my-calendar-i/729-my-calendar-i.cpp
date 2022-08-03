class MyCalendar {
public:
    set<pair<int,int>> st ;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
        for(auto it: st){
            int s =it.first, e =it.second ;
            
            if((start<e) && (s<end))    return false ;
        }
        
        st.insert({start, end}) ;
        return true ;
    }
};
