class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans ;
        
        if(nums.empty())
            return ans ;
        
        sort(nums.begin() ,nums.end()) ;
        
        for(int i=0 ;i< nums.size() ;i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                
                int front= j+1 ;
                int back=nums.size()-1 ;
                int sum1=target - nums[i] - nums[j] ;
                
                while(front < back){
                    int sum2=nums[front] + nums[back] ;
                    if(sum2 < sum1)       front++ ;
                    else if(sum2 > sum1)  back-- ;
                    else{
                        vector<int>quad(4) ;
                        quad[0]=nums[i] ;
                        quad[1]=nums[j] ;
                        quad[2]=nums[front] ;
                        quad[3]=nums[back] ;
                        
                        ans.push_back(quad) ;
                        
                        while(front < back && nums[front]==quad[2]) ++front ;
                        while(front < back && nums[back]==quad[3])  --back ;
                    }
                }
                while(j+1 < nums.size() && nums[j]==nums[j+1]) ++j;
            }
            while(i+1 < nums.size() && nums[i]==nums[i+1]) ++i;
        }
        
        return ans ;
    }
};