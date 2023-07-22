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
    if(val == -1) root = NULL;
    else root = new Node (val);

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

void insert(Node *&root, int x){
    if(root == NULL) {
        root = new Node (x);
        return;
    }

    if(x < root->val){
        if(root->left == NULL) {
            root->left = new Node (x);
        } 
        else insert(root->left, x);
    }
    else {
        if(root->right == NULL) root->right = new Node (x);
        else insert(root->right, x);
    }
}

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

int main()
{
    Node *root = takingInput();

    int x; cin>>x;

    levelOder(root);
    cout<<endl;

    insert(root, x);

    levelOder(root);
    
    return 0;
}


// input ----> 10 5 15 2 6 12 16 -1 3 -1 -1 -1 -1 -1 -1 -1 -1
// 7