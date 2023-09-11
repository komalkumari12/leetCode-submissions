//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        if(!root)   return 0 ;
        
        //store parNode in map
        map<Node*, Node*> mpp  ; //currNode, parNode
        queue<Node*> q ;
        
        mpp[root] = NULL ;
        q.push(root) ;
        
        Node* tarNode = NULL ;
        while(!q.empty()){
            int size = q.size() ;
            
            for(int i=0; i<size; i++){
                Node* node = q.front() ;
                q.pop() ;
                
                if(node->data == target)    tarNode = node ;
                
                if(node->left){
                    q.push(node->left) ;
                    mpp[node->left] = node ;
                }
                if(node->right){
                    q.push(node->right) ;
                    mpp[node->right] = node ;
                }
            }
        }
        
        int burnTime = 0 ;
        set<Node*> st ;
        st.insert(tarNode) ;
        q.push(tarNode) ;
        
        while(!q.empty()){
            int size = q.size() ;
            burnTime++ ;
            
            for(int i=0; i<size; i++)
            {
                Node* node = q.front() ;
                q.pop() ;
                
                if(node->left && st.find(node->left) == st.end())   {
                    st.insert(node->left) ;
                    q.push(node->left) ;
                }
                if(node->right && st.find(node->right) == st.end()){
                    st.insert(node->right) ;
                    q.push(node->right) ;
                }   
                if(mpp.find(node) != mpp.end()){
                    Node* par = mpp[node] ;
                    
                    if(par && st.find(par) == st.end()){
                        st.insert(par) ;
                        q.push(par) ;
                    }
                }
            }
        }
        
        return burnTime-1 ;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends