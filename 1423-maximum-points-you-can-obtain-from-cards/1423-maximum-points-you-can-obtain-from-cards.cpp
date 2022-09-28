class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        /*
        int size = cardPoints.size()-k ;
        int left=0, right=0, minSum=INT_MAX, currSum=0 ;
        
        while(right < cardPoints.size()){
            currSum += cardPoints[right] ;
            
            if(right-left+1 == size){
                minSum = min(minSum, currSum) ;
                currSum -= cardPoints[left] ;
                left++ ;
            }
            
            // minSum = min(minSum, currSum) ;
            right++ ;
        }
        
        return minSum ;
        */
        
        int n= cardPoints.size(), size = n-k ;
        int left=0, right=0, sum =0, minSum=INT_MAX, totalSum =0 ;
        
        while(right < n){
            totalSum += cardPoints[right] ;
            sum += cardPoints[right] ;
            
            if(right-left+1 == size){
                minSum = min(minSum, sum) ;
                sum -= cardPoints[left] ;
                left++ ;
            }
            
            right++ ;
        }
        
        cout<<totalSum<<"  "<<minSum<<"  "<<endl ; 
        if(size == 0)
            return totalSum ;
        return totalSum - minSum ;
    }
};