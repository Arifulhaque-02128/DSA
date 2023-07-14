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

bool isPerfectTree(Node *root){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left == NULL || root->right == NULL) return false;

    bool l = isPerfectTree(root->left);
    bool r = isPerfectTree(root->right);

    return (l && r);
}

int main()
{

    Node *root = takingInput();

    bool result = isPerfectTree(root);

    if(result) cout<<"YES"<<endl;
    else cout<<"NO" <<endl;

    
    return 0;
}

// input -----> 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

// input -----> 10 20 30 40 -1 60 -1 -1 -1 -1 -1

// input -----> 10 20 -1 -1 -1

// input -----> 10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1