class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxProd=0, currProd=1 ;
        
        int start=0, end=height.size()-1 ;
        
        while(start<=end){
            int width=end-start ;
            int heightA=min(height[start],height[end]) ;
            
            currProd=width*heightA ;
            
            maxProd=max(maxProd , currProd) ;
            
            if(height[start]<height[end])
                start++ ;
            
            else if(height[start]>height[end])
                end-- ;
            
            else{
                start++ ;
                end-- ;
            }
                
        }
        
        return maxProd ;
    }
};