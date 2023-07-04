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

void insertAtHead(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head =  newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtPos(Node *head, int pos, int val){
    Node *newNode = new Node (val);
    Node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    newNode->prev = tmp;
    tmp->next = newNode;
}

void printLinkedList(Node *n){
    if(n == NULL){
        return;
    }
    cout<<n->val<<" ";
    printLinkedList(n->next);
}

void printLinkedListReverse(Node *n){
    if(n == NULL) return;
    printLinkedListReverse(n->next);
    cout<<n->val<<" ";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q; cin>>q;
    for (int i = 0; i < q; i++)
    {
        int pos, val; cin>>pos>>val;
        if(pos > findSize(head)){
            cout<<"Invalid"<<endl;
            continue;
        } else if(pos == 0){
            insertAtHead(head, tail, val);
        } else if(pos == findSize(head)){
            insertAtTail(head, tail, val);
        } else {
            insertAtPos(head, pos, val);
        }
        printLinkedList(head);
        cout<<endl;
        printLinkedListReverse(head);
        cout<<endl;
    }
    
    
    return 0;
}



// input ----> 6
// 0 10
// 1 20
// 4 30
// 0 30
// 1 40
// 5 50