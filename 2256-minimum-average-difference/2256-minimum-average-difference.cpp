class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size() ; 
        vector<long long> prefixSum(n, 0) ;
        
        long long sum =0 ;
        for(int i=0; i<n; i++){
            sum+= nums[i] ;
            prefixSum[i] = sum ;
        }
        
        int miniInd = -1 ;
        int mini = INT_MAX ;
        
        for(int i=0; i<n; i++){
            int firstAvg = (prefixSum[i]/(i+1)) ; 
            int secondAvg = 0 ;
            
            if(i == n-1)
                secondAvg = prefixSum[n-1] - prefixSum[i] ;
            else
                secondAvg = (prefixSum[n-1] - prefixSum[i])/(n-(i+1)) ;
            
            int avg = abs(firstAvg - secondAvg) ;
            if(mini > avg){
                mini = avg ;
                miniInd = i ;
            }
        }
        
        return miniInd ;
    }
};