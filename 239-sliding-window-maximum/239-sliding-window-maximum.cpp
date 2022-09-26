class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0, right =0 ;
        priority_queue<pair<int,int>> pq ;
        vector<int> ans ;
        
        while((right + left  <k-1)){
            pq.push({nums[right], right}) ;
            right++ ;
        }
        
        // while(!pq.empty()){
        //     cout<<pq.top().first<<"  "<<pq.top().second<<endl ;
        //     pq.pop() ;
        // }
        cout<<left<<"  "<<right<<endl ;
        
        
//         while(right < nums.size()){
//             if((right - left +1) < k  && right<nums.size()-1){
//                 right++ ;
//                 pq.push({nums[right], right}) ;
//             }
                
//             while(!pq.empty() && (pq.top().second > right || pq.top().second < left)){
//                 //not in range
//                 pq.pop() ;
//             }
            
//             // int maxEle = -1 ;
//             // if(!pq.empty()){
//             //     maxEle = pq.top().first ;
//             // }
                
//             ans.push_back(pq.top().first) ;
//             left++ ;
//         }
        
        while(right< nums.size()){
            // right++ ;
            // left++;
            pq.push({nums[right], right}) ;
            right++  ;
            
            while(!pq.empty() && (pq.top().second > right || pq.top().second < left)){
                pq.pop() ;
            }
            
            // cout<<left<<" "<<right<<endl ;
            ans.push_back(pq.top().first) ;
            left++ ;
        }
        
        return ans ;
    }
};