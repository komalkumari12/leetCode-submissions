class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
       int i ,first=-1 ,size=seats.size(),maxDis=0;
        
        for( i=0; i<size ;i++){
            if(seats[i]==1){
                if(first==-1) maxDis= i ;
                else
                    maxDis=max(maxDis , (i-first)/2) ;
                first=i ;    
            }
        }
        if(seats[size-1]==0) maxDis = max(maxDis, size-1-first );
        
        return maxDis ;
    }
};
