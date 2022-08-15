class Solution {
public:
    int romanToInt(string s) {
        int sum =0 ;
        stack<char> st ;
        unordered_map<char, int> mpp ;
        mpp['I'] = 1 ;
        mpp['V'] = 5 ;
        mpp['X'] = 10 ;
        mpp['L'] = 50 ;
        mpp['C'] = 100 ;
        mpp['D'] = 500 ;
        mpp['M'] = 1000 ;
        
        
        for(int i=0; i<s.size(); i++){
            int val = mpp[s[i]] ;
            
            if(!st.empty() && val > mpp[st.top()]){
                sum += val - mpp[st.top()] ;
                st.pop() ;
            }
            else
                st.push(s[i]) ;
        }
        
        while(!st.empty()){
            sum += mpp[st.top()] ;
            st.pop() ;
        }
        
        return sum ;
    }
};