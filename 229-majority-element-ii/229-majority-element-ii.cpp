//Moore's Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1 ,num2=-1 ;
        int c1=0 , c2=0 ;
        
        for(int i=0; i<nums.size() ;i++){
            if(num1==nums[i]) c1++ ;
            else if(num2==nums[i]) c2++ ;
            else if(c1==0){
                c1=1 ;
                num1=nums[i] ;
            }
            else if(c2==0){
                c2=1 ;
                num2=nums[i] ;
            }
            else{
                c1--;
                c2-- ;
            }
        }
          
        int count1=0 ,count2=0 ;
        vector<int> ans ;
        
        for(int i=0; i<nums.size() ;i++){
            if(nums[i]==num1) count1++ ;
            if(nums[i]==num2) count2++ ;
        }
        
        if(count1 > nums.size()/3)
            ans.push_back(num1) ;
        if(num1 != num2  &&  count2 > nums.size()/3)
            ans.push_back(num2) ;
        
        return ans; 
        
    }
};