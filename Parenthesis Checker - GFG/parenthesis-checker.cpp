//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string str)
    {
        stack<char> st ;
        int n = str.size() ;
        
        for(int i=0; i<n; i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
                st.push(str[i]) ;
            else{
                if(st.empty())  return false ;
                else{
                    char topBracket = st.top() ;
                    
                    if(topBracket == '(' && str[i] == ')' || topBracket == '{' && str[i] == '}' || topBracket == '[' && str[i] == ']')
                        st.pop() ;
                    else
                        return false ;
                }
            }        
        }
        
        if(!st.empty()) return false ;
        return true ;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends