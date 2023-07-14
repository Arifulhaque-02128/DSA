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
        else leftNode = new Node (l);

        if(r == -1) rightNode = NULL;
        else rightNode = new Node (r);

        p->left = leftNode;
        p->right = rightNode;

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

int mx = INT_MIN;
int mn = INT_MAX;

void maxMinLeaf(Node *root){

    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        if(root->val > mx) mx = root->val;
        if(root->val < mn) mn = root->val;
        return;
    }
    maxMinLeaf(root->left);
    maxMinLeaf(root->right);
}

int main()
{
    Node *root = takingInput();

    maxMinLeaf(root);

    cout<<mx<<" "<<mn<<endl;
    
    return 0;
}


// input ------> 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1