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

Node *takingInput(){
    int val; cin>>val;
    Node *root;
    if(val == -1 ) root = NULL;
    else root = new Node(val);

    queue<Node *> q;
    if(root) q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r; cin>>l>>r;
        Node *leftNode;
        Node *rightNode;

        if(l == -1) leftNode = NULL;
        else leftNode = new Node(l);

        if(r == -1) rightNode = NULL;
        else rightNode = new Node(r);

        p->left = leftNode;
        p->right = rightNode;

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

int sum = 0;

void leftSum(Node *root){
    if(root == NULL) return;
    if(root->left) {
        sum = sum + root->left->val;
    }

    leftSum(root->left);
    leftSum(root->right);
}

int main()
{
    Node *root = takingInput();

    leftSum(root);

    cout<<sum<<endl;
    
    return 0;
}


// input ----> 1 2 3 4 5 -1 -1 6 -1 -1 -1 -1 -1

// input ------> 3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1