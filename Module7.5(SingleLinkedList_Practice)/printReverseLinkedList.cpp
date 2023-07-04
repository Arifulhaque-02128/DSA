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
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    
    tail->next = newNode;
    tail = newNode;
}

void printReverese(Node *n){
    if(n == NULL) return;
    printReverese(n->next);
    cout<<n->val<< " ";
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin>>val;
        if (val == -1) break;
        insertAtTail(head, tail, val);
    }

    printReverese(head);
    
    
    return 0;
}


// input ---> 5 1 4 5 -1

// input ----> 1 2 3 4 -1