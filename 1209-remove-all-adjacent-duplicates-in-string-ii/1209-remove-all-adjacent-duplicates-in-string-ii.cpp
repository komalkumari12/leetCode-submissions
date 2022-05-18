class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st ;      //{char, freq}
        
        for(int i=0; i<s.size(); i++){
            if(!st.empty()  && s[i] == st.top().first){
                st.top().second++ ;
            }
            else{
                st.push({s[i], 1}) ;
            }
            
            if(!st.empty()  &&  st.top().second == k)
                st.pop() ;
            
        }
        
        string str ="" ;
        while(!st.empty()){
            int freq = st.top().second ;
            char ch = st.top().first ;
            st.pop() ;
            
            while(freq--){
                str += ch ;
            }
        }
        
        reverse(str.begin(), str.end()) ;
        return str ;
    }
};