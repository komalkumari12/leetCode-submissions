class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans ;
        
        if(nums.empty() || nums.size() < 3)
            return ans ;
        
        sort(nums.begin(), nums.end()) ;
        
        for(int i=0 ;i<nums.size(); i++){
            
            int front=i+1 ;
            int back=nums.size()-1 ;
            
            while(front < back){
                int temp_sum=nums[i] + nums[front] ;
                
                if(temp_sum + nums[back]  > 0)
                    back-- ;
                
                else if( temp_sum + nums[back]  < 0)
                    front++ ;
                
                else{
                    vector<int> triplet(3 , 0) ;
                    triplet[0]=nums[i] ;
                    triplet[1]=nums[front] ;
                    triplet[2]=nums[back] ;
                    
                    ans.push_back(triplet) ;
                    
                    while(front < back  &&  nums[front]==triplet[1])  ++front ;
                    while(front < back  &&  nums[back]==triplet[2])  --back ;
                }
            }
            while(i+1 < nums.size()  && nums[i+1]== nums[i]) ++i ;
        }
        
        return ans ;
    }
};