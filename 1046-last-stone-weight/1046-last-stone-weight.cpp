class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq; 
        
        for(int i=0; i<stones.size() ;i++)
            pq.push(stones[i]) ;
        
        while(pq.size() > 1){
            int first= pq.top() ;  
            pq.pop() ;
            int second= pq.top() ;
            pq.pop() ;
            
            cout<<first<<"  "<<second<<"  " ;
            
            if(first != second){
                if(first <= second){
                    pq.push(second-first) ;
                    cout<<second-first<<"  ";
                }
                else{
                    pq.push(first-second) ;
                    cout<<first-second<<"  " ;
                }
            }
            cout<<endl ;
        }
        
        if(!pq.empty())
            return pq.top() ;
        return 0 ;
    }
};