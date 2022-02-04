class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0; i<nums.size() ;i++)
            if(nums[i]==0)
                nums[i]= -1 ;
        
        
        int result=0 ;
        int sum=0;
        unordered_map<int,int> mp ;
        
        for(int i=0; i<nums.size() ;i++){
            sum+=nums[i] ;
            
            if(sum==0)
                result = max(result , i+1) ;
            if(mp.find(sum) != mp.end())
                result=max(result,i-mp[sum]) ;
            else
                mp[sum]= i ;
        }
        return result ;    
    }
};