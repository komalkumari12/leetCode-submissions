class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sum = INT_MAX ;
        map<string, int> mpp ;
        vector<string> ans ;
        
        for(int i=0; i<list1.size(); i++){
            mpp[list1[i]] = i ;
        }
        
        for(int i=0; i<list2.size(); i++){
            if(mpp.find(list2[i])!= mpp.end()){
                
                // if(mpp[list2[i]]+ i < sum){
                //     // restro = list2[i]  ;
                //     ans.push_back(list2[i]) ;
                //     sum = mpp[list2[i]]+ i  ;
                // }
                
                if(mpp[list2[i]]+ i < sum){
                    ans.clear() ;
                    sum = mpp[list2[i]]+ i  ;
                }
                
                if(mpp[list2[i]]+ i <= sum){
                    ans.push_back(list2[i]) ;
                }
            }
        }
        
        return ans ;
    }
};