class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0;  //nums1
        int j = 0;  //nums2
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;
        
        while(i != n1 && j != n2 ){
            if(nums1[i] <= nums2[j])
                ans.push_back(nums1[i++]) ;  
            else
                ans.push_back(nums2[j++]) ;  
        }
        
        while(i != n1)
            ans.push_back(nums1[i++]) ;

        while(j != n2)
            ans.push_back(nums2[j++]) ;
        
        int size = n1 + n2 ;
        if(size%2 == 0)  return (ans[size / 2] + ans[size/ 2-1] )/ 2.0;
        else return ans[size/2] ;
    }
};