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

void printNormal(Node *head){
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    
}

void printReverse(Node *tail){
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->prev;
    }
    cout<<endl;
}

void insertAtPos(Node *head, int pos, int val){
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = tmp;
}

void insertAtHead(Node *&head, int val){
    Node *newNode = new Node (val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;    
}

void insertAtTail(Node *&tail, int val){
    Node *newNode = new Node(val);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}


int findSize(Node *head){
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *tail = c;

    // connections
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    // print doubly linked list
    printNormal(head);
    printReverse(tail);

    // insert at doubly linked list

    int pos, val; cin>>pos>>val;
    if(pos > findSize(head)) cout<<"Invalid Index"<<endl;
    else if(pos == 0) insertAtHead(head, val);
    else if(pos == findSize(head)) insertAtTail(tail, val);
    else insertAtPos(head, pos, val);
    


    // print doubly linked list
    printNormal(head);
    printReverse(tail);
    
    
    return 0;
}


// input ----> 0 100
// input ----> 2 100
// input ----> 4 100
// input ----> 5 100