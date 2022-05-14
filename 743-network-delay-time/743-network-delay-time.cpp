class Solution {
public:
     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int,int>>> adjlist(n+1);
     
        for(auto ele:times){
            adjlist[ele[0]].push_back({ele[1],ele[2]});    
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        dist[k]=0;
        pq.push({0,k}); 
        
        while(!pq.empty()){
            int node=pq.top().second;
            int cost=pq.top().first;
             visited[node]=true;
            pq.pop();
            for(auto ele : adjlist[node]){
                int next_node=ele.first;
                int cost=ele.second;
                if(!visited[next_node] && dist[next_node]>dist[node]+cost){
                    dist[next_node]=dist[node]+cost;
                    pq.push({dist[next_node],next_node});
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=1;i<dist.size();i++) ans=max(ans,dist[i]);
        
        if(ans==INT_MAX) return -1;
        return ans;
        
        
    }
};