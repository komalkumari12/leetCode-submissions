// { Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNewNode(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *tree, int val) {

    if (tree == NULL) {
        return createNewNode(val);
    }

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


 // } Driver Code Ends
// User function Template for C

// Function to search a struct node in BST.
bool search(struct Node* root, int x) {
    if(!root) return false ;
    
    if(root->data == x) return true ;
    
    return search(root->left, x) || search(root->right, x) ;
}


// { Driver Code Starts.

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        struct Node *root = NULL;

        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int k;
            scanf("%d", &k);
            root = insert(root, k);
        }

        int s;
        scanf("%d", &s);

        bool ans = search(root, s);

        if (ans) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}
  // } Driver Code Ends