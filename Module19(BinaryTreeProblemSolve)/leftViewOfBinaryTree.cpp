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

vector<int> leftView(Node *root){

    vector<int> v;
    if(root == NULL) return v;
    queue<pair<Node *, int>> q;
    q.push({root, 1});

    int currentLevel = 1;
    v.push_back(root->val);

    while (!q.empty())
    {
        Node *p = q.front().first;
        int level = q.front().second;
        q.pop();

        if(currentLevel != level){
            currentLevel = level;
            v.push_back(p->val);
        }

        if(p->left) q.push({p->left, level+1});
        if(p->right) q.push({p->right, level+1});

    }

    return v;
}


int main()
{

    Node *root = takingInput();

    vector<int> v = leftView(root);

    for(int val: v){
        cout<<val<<" ";
    }
    
    return 0;
}

// input ----> 3 4 -1 -1 -1 

// input -----> 2 8 7 -1 5 -1 -1 1 -1 -1 -1