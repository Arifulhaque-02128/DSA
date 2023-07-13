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

int nodeLevel(Node *root, int x){

    if(root == NULL) return 0;

    queue<pair<Node *, int>> q;
    q.push({root, 1});

    while (!q.empty())
    {
        Node *p = q.front().first;
        int level = q.front().second;
        q.pop();

        if(p->val == x){
            return level;
        }

        if(p->left) q.push({p->left, level+1});
        if(p->right) q.push({p->right, level+1});
    }

    return 0;
}

int main()
{

    Node *root = takingInput();
    int x; cin>>x;

    int level = nodeLevel(root, x);

    cout<<level<<endl;
    
    return 0;
}

// input ----> 1 2 3 -1 -1 -1  6 -1 -1
// 6

// input -----> 1 2 -1 -1 -1
// 1