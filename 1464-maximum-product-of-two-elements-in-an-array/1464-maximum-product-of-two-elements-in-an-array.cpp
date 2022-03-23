class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //minHeap
        priority_queue<int, vector<int> , greater<int>> pq ;
        
        for(int i=0; i<nums.size() ;i++){
            pq.push(nums[i]) ;
            
            if(pq.size() > 2)
                pq.pop() ;
        }
        
        int prod =1 ;
        while(!pq.empty()){
            prod *= pq.top() -1 ;
            pq.pop() ;
        }
        
        return prod ;
    }
};