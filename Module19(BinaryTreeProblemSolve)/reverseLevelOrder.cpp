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

vector<int> reverseLevelOrderTraversal(Node *root){
    vector<int> v;
    if(root == NULL) return v;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        v.push_back(p->val);

        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    Node *root = takingInput();

    vector<int> rev = reverseLevelOrderTraversal(root);

    for(int val: rev){
        cout<<val<< " ";
    }
    
    return 0;
}

// input ----> 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

// input ----> 2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1