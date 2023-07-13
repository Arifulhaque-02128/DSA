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

vector<int> v;

void postOrderTraversal(Node *root){
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    v.push_back(root->val);

}

int main()
{
    Node *root = takingInput();

    postOrderTraversal(root);

    for(int val:v){
        cout<<val<<" ";
    }

    return 0;
}

// input ----> 1 2 3 4 -1 -1 5 6 7 -1 -1 -1 -1 -1 -1

// input ----> 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1