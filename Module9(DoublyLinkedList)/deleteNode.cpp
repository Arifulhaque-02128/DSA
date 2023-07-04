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


void deleteFromPos(Node *head, int pos){
    Node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

void deleteHead(Node *&head){
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
    head->prev = NULL;
}

void deleteTail(Node *&tail){
    Node *deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    tail->next = NULL;
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


    // delete node from doubly linked list
    int pos; cin>>pos;
    if(pos >= findSize(head)){
        cout<<"Invalid Index"<<endl;
    }
    else if (pos == (findSize(head)-1)){
        deleteTail(tail);
    }
    else if (pos == 0)
    {
        deleteHead(head);
    } else {
        deleteFromPos(head, pos);
    }

    // print doubly linked list
    printNormal(head);
    printReverse(tail);

    return 0;
}


// input ----> 0 or 2 or 3 or 4