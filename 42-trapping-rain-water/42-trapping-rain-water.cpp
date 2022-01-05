class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left ;
        vector<int> right ;
        int trappedWater=0 ;
        
        int leftMin=INT_MIN;
        int rightMax=INT_MIN ;
        
        for(int i=0;i<height.size();i++){
            leftMin=max(leftMin,height[i]);
            left.push_back(leftMin);
        }
        
        for(int i=height.size()-1;i>=0;i--){
            rightMax=max(rightMax,height[i]);
            right.push_back(rightMax);
        }
        
         reverse(right.begin(), right.end());
        
        for(int i=0; i<height.size();i++){
            trappedWater+=min(left[i],right[i])-height[i] ;
        }
        
        return trappedWater;
    }
};