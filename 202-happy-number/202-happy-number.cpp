class Solution {
public:
    bool isHappy(int num) {
        
        while(num != 1){
            int sqSum=0; 
            
            while(num>0){
                int rem = num%10 ;
                sqSum += rem * rem ;
                num=num/10 ;
            }
            
            num=sqSum ;
            if(num==89) return false ;
        }
        return true ;
    }
};