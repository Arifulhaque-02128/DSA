#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int val;
        Node * left;
        Node *right;
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

bool isSameTree(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    queue<Node *> q1;
    queue<Node *> q2;
    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() || !q2.empty())
    {
        if(q1.empty()){
            if(!q2.empty()) return false;
        }

        if(q2.empty()){
            if(!q1.empty()) return false;
        }

        Node *p1 = q1.front();
        Node *p2 = q2.front();
        q1.pop();
        q2.pop();

        if(p1->val != p2->val){
            return false;
        }

        if(p1->left){
            if(p2->left) q1.push(p1->left);
            else return false;
        }
        if(p1->right) {
            if(p2->right) q1.push(p1->right);
            else return false;
        }

        if(p2->left) {
            if(p1->left) q2.push(p2->left);
            else return false;
        }
        if(p2->right){
            if(p1->right) q2.push(p2->right);
            else return false;
        }
    }

    return true;
}


int main()
{
    Node *root1 = takingInput();
    Node *root2 = takingInput();

    bool result = isSameTree(root1, root2);

    if(result) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}

// input -----> 1 2 3 -1 -1 -1 -1
// 1 2 3 -1 -1 -1 -1