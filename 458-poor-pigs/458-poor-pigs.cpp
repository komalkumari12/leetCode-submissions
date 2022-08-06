class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets == 1)    return 0 ;
        
        int div = minutesToTest/minutesToDie +1 ;
        int ans=0 ;
        buckets-- ;
        
        while(buckets > 0){
            buckets /= div ;
            ans++ ;
        }
        
        return ans ;
    }
};