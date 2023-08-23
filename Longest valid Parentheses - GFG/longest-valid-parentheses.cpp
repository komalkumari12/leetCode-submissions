//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        int n = S.size() ;
        int len =0 ;
        int maxLen = 0 ;
        
        stack<int> st ;
        st.push(-1) ;
        
        for(int i=0; i<n; i++){
            if(S[i] == '('){
                st.push(i) ;
            }
            else{
                if(!st.empty()){
                    st.pop() ;
                }
                if(!st.empty()){
                    len = i - st.top() ;
                    maxLen = max(maxLen, len) ;
                }
                else{
                    st.push(i) ;
                }
            }
        }
        
        return maxLen ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends