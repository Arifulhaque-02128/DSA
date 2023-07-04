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

void insertAtTail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void printLinkedList(Node *n){
    if(n == NULL) return;
    cout<<n->val<<" ";
    printLinkedList(n->next);
}

void printReverse(Node *n){
    if(n == NULL) return;
    
    printReverse(n->next);
    cout<<n->val<<" ";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin>>val;
        if(val == -1) break;
        insertAtTail(head, tail, val);
    }

    printReverse(head);
    cout<<endl;
    printLinkedList(head);
    
    
    return 0;
}

// input ----> 10 20 30 40 50 -1

// input -----> 20 40 50 10 -1