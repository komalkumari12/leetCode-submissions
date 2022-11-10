class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st ;
        
        for(int i=0; i<s.size(); i++){
            bool check = false ;
            
            while(!st.empty() && st.top() == s[i]){
                st.pop() ;
                check = true ;
            }
            
            if(!check)
                st.push(s[i]) ;
        }
        
        string ans = "" ;
        while(!st.empty()){
            ans += st.top() ;
            st.pop() ;
        }
        
        reverse(ans.begin(), ans.end()) ;
        return ans ;
    }
};