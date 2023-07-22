#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int val;
        Node * left;
        Node * right;
    Node (int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOder(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout<<p->val<<" ";

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
}

Node *convert(int arr[], int size, int start, int end){

    if(start > end) return NULL;

    int mid = (start + end) / 2;
    Node *root = new Node (arr[mid]);
    Node *leftNode = convert(arr, size, start, mid-1);
    Node *rightNode = convert(arr, size, mid+1, end);

    root->left = leftNode;
    root->right = rightNode;

    return root;
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i]; // input array must be sorted
    }
    
    Node *root = convert(arr, n, 0, n-1);

    levelOder(root);

    return 0;
}

// input ----> 6
// 2 5 8 12 15 18