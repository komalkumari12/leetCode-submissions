/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
int bin(int l,int r)
{
    if(l>r) return -1;
    //if(l==r) return l;

    int mid=l+(r-l)/2;

    int g=guess(mid);

    if(g==0) return mid;
    else if(g==-1) return bin(l,mid-1);
    else return bin(mid+1,r);
}
    
int guessNumber(int n) {
    return bin(1,n);
}  
};