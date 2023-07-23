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

Node *array_to_bst(vector<int> v, int sz, int l, int r){

    if(l>r) return NULL;

    int mid = (l+r)/2;
    Node *root = new Node (v[mid]);
    Node *leftNode = array_to_bst(v, sz, l, mid-1);
    Node *rightNode = array_to_bst(v, sz, mid+1, r);

    root->left = leftNode;
    root->right = rightNode;

    return root;
}

Node *convert(vector<int> &v){

    int sz = v.size();
    if(sz == 0) return NULL;
    int l = 0;
    int r = sz -1;

    Node *root = array_to_bst(v, sz, l, r);

    return root;

}

void level_order(Node *root){
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

int sum = 0;
void rangeSum(Node *root, int low, int high){

    if(root == NULL) return;
    if(root->val >= low && root->val <= high){
        sum += root->val;
    }

    rangeSum(root->left, low, high);
    rangeSum(root->right, low, high);

}


int main()
{

    int n; cin>>n;
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        vec.push_back(val);
    }


    for (int i = 0; i < vec.size()-1; i++)
    {
        for (int j = i+1; j < vec.size(); j++)
        {
            if(vec[i] > vec[j]){
                swap(vec[i], vec[j]);
            }
        }
    }
    

    Node *root = convert(vec);

    level_order(root);
    cout<<endl;

    int low, high; cin>>low>>high;
    rangeSum(root, low, high);

    cout<<sum<<endl;
    
    return 0;
}


// input ----> 6
// 10 5 15 3 7 18