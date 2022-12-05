class DisjoinSet{
    vector<int> parent, rank, size ;
    public:
        DisjoinSet(int n){
            parent.resize(n+1) ;
            rank.resize(n+1, 0) ;
            size.resize(n+1, 1) ;
            
            for(int i=0; i<n+1; i++)
                parent[i] = i ;
        }
        
        int findParent(int node){
            if(parent[node] == node)
                return node ;
            return parent[node] = findParent(parent[node]) ;
        }
        
        void unionByRank(int u, int v){
            int par_u = findParent(u) ;
            int par_v = findParent(v) ;
            
            if(par_u == par_v)  return ;
            if(rank[par_v] < rank[par_u]){
                parent[par_v] = par_u ;
            }
            else if(rank[par_v] > rank[par_u]){
                parent[par_u] = par_v ;
            }
            else{
                parent[par_v] = par_u ;
                rank[par_u]++ ;
            }
        }
        
        void unionBySize(int u, int v){
            int par_u = findParent(u) ;
            int par_v = findParent(v) ;
            
            if(par_u == par_v)  return ;
            if(size[par_u] < size[par_v]){
                parent[par_u] = par_v ;
                size[par_v] += size[par_u] ;
            }
            else{
                parent[par_v] = par_u ;
                size[par_u] += size[par_v] ;
            }
        }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjoinSet ds(n) ;
        
        queue<int> q;
        q.push(0) ;
        int ind= 0;
        
        // check indegree of nodes , if 2 or more nodes have indegree as 0 than tree is not possiblle
        vector<int> indegree(n, 0) ;
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1)
                indegree[leftChild[i]]++ ;
            if(rightChild[i] != -1)
                indegree[rightChild[i]]++ ;
        }
        
        int root_nodes =0 ;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
                root_nodes++ ;
            
            if(root_nodes >= 2)
                return false ;
        }

        for(int ind=0; ind<n; ind++){
            int node = ind ;
            
            if(leftChild[ind] != -1){
                if(ds.findParent(node) != ds.findParent(leftChild[ind])){
                    ds.unionBySize(node, leftChild[ind]) ;
                }
                else
                    return false ;
            }
            if(rightChild[ind] != -1){
                if(ds.findParent(node) != ds.findParent(rightChild[ind])){
                    ds.unionBySize(node, rightChild[ind]) ;
                }
                else
                    return false ;
            }
        }
        
        return true ;
    }
};