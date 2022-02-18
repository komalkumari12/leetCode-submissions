class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int revNum =0 ;

        for(int i=0; i<32; i++){
            revNum<<=1 ;
            if(n&1 > 0)
                revNum++;
            n>>=1 ;
        }
        return revNum ;
    }
};