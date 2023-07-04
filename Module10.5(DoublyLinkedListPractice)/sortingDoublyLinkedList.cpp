#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int val;
        Node * prev;
        Node * next;
    Node (int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printLinkedList(Node *n){
    if(n == NULL) return;
    cout<<n->val<<" ";
    printLinkedList(n->next);
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

    for (Node * i = head; i->next != NULL; i=i->next)
    {
        for (Node * j = i->next; j != NULL; j=j->next)
        {
            if(i->val > j->val) swap(i->val, j->val);
        }
    }

    printLinkedList(head);
    
    
    return 0;
}



// input ---> 1 4 5 2 7 -1


// input ----> 20 40 30 10 50 60 -1