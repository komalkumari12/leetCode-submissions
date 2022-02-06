/*  Approach
        **Vector is sorted**
        Use 2 pointer Approach
*/

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums){
    int i =0 ;
    int j=nums.size()-1 ;
    vector<int> squares(nums.size());
    
    for(int k=nums.size()-1 ;k>=0 ;k--){
        if(nums[i]*nums[i] <=nums[j]*nums[j]){
            squares[k] = nums[j]*nums[j] ;
            j--;
        }
        else{
            squares[k]=nums[i]*nums[i] ;
            i++ ;
        }
    }
    return squares ;
}
};