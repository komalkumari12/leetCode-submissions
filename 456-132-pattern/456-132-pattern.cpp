class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> st ;
        int mini =nums[0] ;
        
        for(int i=1; i<nums.size(); i++){
            while(!st.empty()  &&  st.top().first <= nums[i])
                st.pop() ;
            
            if(!st.empty()  &&  nums[i] > st.top().second)
                return true ;
                
            st.push({nums[i],mini}) ;
            mini = min(mini, nums[i]) ;
        }
        
        return false ;
    }
};
