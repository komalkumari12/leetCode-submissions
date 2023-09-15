//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int singleDigit(long long num)
    {
        
        while(num >9){
            long long n = num ;
            int sum = 0;
            
            while(n){
                sum += n %10 ;
                n = n/ 10 ;
            }
            
            num = sum ;
        }
        
        return num ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        int ans  = ob.singleDigit(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends