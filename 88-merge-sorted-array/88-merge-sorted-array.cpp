class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lastEle = m+n-1 ;
        
        while(m && n){
            if(nums1[m-1] >= nums2[n-1]){
                nums1[lastEle] = nums1[m-1] ;
                m-- ;
            }
            else{
                nums1[lastEle] = nums2[n-1] ;
                n-- ;
            }
            
            lastEle-- ;
        }
        
        while(n){
            nums1[lastEle] = nums2[n-1] ;
            n-- ;
            lastEle-- ;
        }
    }
};