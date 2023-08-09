//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        stack<int> st ;
        int n = str.size() ;
        
        for(int i=0; i<n; i++){
            if (isdigit(str[i])){
                st.push(str[i] - '0');
                // cout<<"Pushed into stack : "<<str[i]<<endl ;
            }
            else{
                // cout<<"POP Operation"<<endl ;
                
                int num2 =st.top() ; st.pop() ;
                int num1 = st.top() ; st.pop() ;
                
                int op = str[i] ;
                
                switch(op)
                {
                    case '+':
                        st.push(num1 + num2) ;
                        // cout<<"Pushed : "<<num1 + num2<<endl ;
                        break ;
                    case '-':
                        st.push(num1 - num2) ;
                        // cout<<"Pushed : "<<num1 - num2<<endl ;
                        break ;  
                    case '*':
                        st.push(num1 * num2) ;
                        // cout<<"Pushed : "<<num1 * num2<<endl ;
                        break ;
                    case '/':
                        st.push(num1 / num2) ;
                        // cout<<"Pushed : "<<num1 / num2<<endl ;
                        break ;    
                    
                }
            }
        }
        
        return st.top() ;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends