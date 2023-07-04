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

void insertAtHead(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtPos(Node *head, int pos, int val){
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    newNode->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
}

void displayList(Node *head){
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void displayListReverse(Node *n){
    if(n == NULL) return;
    displayListReverse(n->next);
    cout<<n->val<<" ";
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

    Node *head = NULL;
    Node *tail = NULL;
    int q; cin>>q;
    for (int i = 0; i < q; i++)
    {
        int pos, val; cin>>pos>>val;
        if(pos > findSize(head)){
            cout<<"Invalid"<<endl;
        } else if (pos == 0){
            insertAtHead(head, tail, val);
            cout<<"L -> ";
            displayList(head);
            cout<<"R -> ";
            displayListReverse(head);
            cout<<endl;
        } else if (pos == findSize(head)){
            insertAtTail(head, tail, val);
            cout<<"L -> ";
            displayList(head);
            cout<<"R -> ";
            displayListReverse(head);
            cout<<endl;
        } else {
            insertAtPos(head, pos, val);
            cout<<"L -> ";
            displayList(head);
            cout<<"R -> ";
            displayListReverse(head);
            cout<<endl;
        }
    }
    
    
    return 0;
}


// input ----> 5
// 1 10
// 0 10
// 1 20
// 3 30
// 2 30



// input ----> 10
// 0 10
// 1 20
// 0 30
// 1 40
// 6 50
// 0 60
// 4 70
// 4 80
// 2 90
// 1 100