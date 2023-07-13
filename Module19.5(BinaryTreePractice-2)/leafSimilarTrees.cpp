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

vector<int> v1;
vector<int> v2;

void findLeafs(Node *root, int x){

    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL) {
        if(x == 1) {
            v1.push_back(root->val);
            return;
        } else {
            v2.push_back(root->val);
            return;
        }
    }

    findLeafs(root->left, x);
    findLeafs(root->right, x);
}

bool isLeafSimilarTrees(Node *root1, Node *root2){
    findLeafs(root1, 1);
    findLeafs(root2, 2);

    return (v1 == v2);
}


int main()
{
    Node *root1 = takingInput();
    Node *root2 = takingInput();

    bool result = isLeafSimilarTrees(root1, root2);

    if(result) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}


// input ----> 1 2 3 -1 -1 -1 -1
// 1 3 2 -1 -1 -1 -1