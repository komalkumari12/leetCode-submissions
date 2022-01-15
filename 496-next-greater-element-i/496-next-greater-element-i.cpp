class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans ;
        
        for(int i=0; i<nums1.size(); i++){
            int ele=nums1[i] ;
            
            for(int  j=0; j<nums2.size(); j++){
                bool result=false ;
                
                if(nums1[i]==nums2[j]){
                    for(int k=j+1 ; k<nums2.size() ;k++){
                        
                        if(nums2[k]>ele){
                            ans.push_back(nums2[k]) ;
                            result= true ;
                            break ;
                        }
                    }
                    if(result==false ){
                        ans.push_back(-1) ;
                        break ;
                    }
                }
            }
        }
        
        return ans ;
    }
};