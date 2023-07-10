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

Node *takeInput(){
    int val; cin>>val;
    Node *root;
    if(val == -1) root = NULL;
    else root = new Node (val);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r ; cin>>l>>r;
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


void levelOrder(Node *root){
    if(root == NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }

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

int countLeaf(Node *root){
    
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else {
        int l = countLeaf(root->left);
        int r = countLeaf(root->right);

        return (l+r);
    }
}

int main()
{
    Node *root = takeInput();

    int cnt = countLeaf(root);
    cout<<"Total Leaf Node : "<<cnt<<endl;
    
    levelOrder(root);

    return 0;
}