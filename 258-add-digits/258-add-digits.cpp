class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int rem= 0;
            while(num > 0){
                rem += num%10 ;
                num /= 10 ;
            }
            num = rem ;
        }
        return num ;
    }
};