class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0)
                nums[i]= 0;
            else
                nums[i]= 1 ;
        }
        
        unordered_map<int,int> freqMap ;
        int niceSubArray=0, sum=0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i] ;
            
            if(sum == k)
                niceSubArray++ ;
            
            if(freqMap.find(sum-k) != freqMap.end())
                niceSubArray += freqMap[sum-k] ;
            
            freqMap[sum]++ ;
            
        }
        
        return niceSubArray ;
        
        
        
        
        /*
        int niceSubArray= 0, oddNum= 0 ;
        int left =0, right=0 ;
        
        while(right < nums.size()){
            if(nums[right]%2 != 0)
                oddNum++ ;
            
            while(left <= right && oddNum > k){
                if(nums[left]%2 != 0)
                    oddNum-- ;
                
                left++ ;
            }
            
            niceSubArray += right-left+1 ;
            right++ ;
        }
        
        return niceSubArray ;
        */
    }
};

