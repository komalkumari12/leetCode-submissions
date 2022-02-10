class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp ;
        int count=0 ,sum=0 ;
        
        for(int i=0; i< nums.size() ;i++){
            sum+=nums[i] ;
            
            if(sum==k) count++ ;
            if(mpp.find(sum-k) != mpp.end())  count=mpp[sum-k] + count ; 
                
            if(mpp.find(sum) != mpp.end()) mpp[sum]++ ;
            else mpp[sum]=1 ;
        }
        return count ;
    }
};

