class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() < k) return s ;
        
        stack<pair<char,int>>st;
        
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else{
                auto prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        
        string str="";
        
        while(!st.empty()){
            auto element=st.top();
            st.pop();
            while(element.second--){
                str.push_back(element.first);
            }
        }
        reverse(str.begin(), str.end());
        
        return str;
    }
};