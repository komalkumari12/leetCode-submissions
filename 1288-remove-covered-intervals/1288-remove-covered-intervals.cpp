class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int left=-1 ;
        int right=-1 ;
        int count=0 ;
        
        sort(intervals.begin() , intervals.end()) ;
        
        for(auto v: intervals){
            if(v[0]>left  &&  v[1]>right ){
                left=v[0] ;
                count++ ;
            }
            right=max(right ,v[1]) ;
        }
        return count ;
    }
};