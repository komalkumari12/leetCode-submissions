class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> st ;
        vector<int> ans (t.size()) ;
        
        for(int i=t.size()-1; i>=0; i--){
            int day=1 ; 
            while(!st.empty() && st.top().first <= t[i]){
                day += st.top().second ;
                st.pop() ;
            }
            
            if(st.empty()){
                ans[i] = 0 ;
            }
            else
                ans[i] = day ;
            
            st.push({t[i], ans[i]}) ;
        }
        
        return ans ;
    }
};