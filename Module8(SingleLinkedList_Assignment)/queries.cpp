#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int val;
        Node * next;
    Node (int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q; cin>>q;
    for (int i = 0; i < q; i++)
    {
        int x, v; cin>>x>>v;
        if (x == 0)
        {
            insertAtHead(head, tail, v);
        }
        else
        {
            insertAtTail(head, tail, v);
        }

        cout<<head->val<<" "<<tail->val<<endl;
        
    }

    return 0;
}


// input ----> 5
// 0 10
// 0 20
// 1 30
// 0 40
// 1 50


// input -----> 3
// 1 10
// 1 20
// 0 30