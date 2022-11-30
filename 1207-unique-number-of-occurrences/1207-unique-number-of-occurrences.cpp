class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size() ;
        unordered_map<int,int> freq ;
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++ ;
        }
        
        set<int> st ;
        for(auto it : freq){
            int frequency = it.second ;
            
            if(st.find(frequency) != st.end())
                return false ;
            
            st.insert(frequency) ;
        }
        
        return true ;
    }
};