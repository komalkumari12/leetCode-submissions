class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st ;
        
        for(int i =0; i<s.size(); i++){
            if(s[i]=='(' ||  s[i]=='['  ||  s[i]=='{' ){
                st.push(s[i]) ;
            }
            
            else{
                if(st.empty())  return false ;
                
                char c= st.top() ;
                st.pop() ;
                
                if(s[i]=='}' && c=='{' || s[i]==')' && c=='('  || s[i]==']' && c=='[' ) ;
                    
                else{
                        return false ;
                }
                             
            }
        }
        
        if(st.empty())
            return true ;
        return false ;
    }
};

/*
  bool isValid(string A) {
        stack<char> s;
        
        for(int i=0;i<A.size();i++){
            if(A[i]=='('||A[i]=='{'||A[i]=='['){
                s.push(A[i]);
            }
            else{
                if(s.empty()) return false;
                else if(A[i]=='}'){
                    if(s.top()=='{') s.pop();
                    else return false;
                }
                else if(A[i]==')'){
                    if(s.top()=='(') s.pop();
                    else return false;
                }
                else if(A[i]==']'){
                    if(s.top()=='[') s.pop();
                    else return false;
                }
            }
        }
        if(s.empty()) return true;
        return false;
    }

*/