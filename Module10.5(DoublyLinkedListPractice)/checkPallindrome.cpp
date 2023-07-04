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


    // check pallindrome
    bool flag = false;
    Node *i = head;
    Node *j = tail;
    while (i != j && i->next != j)
    {
        if(i->val != j->val){
            flag = true;
            break;
        }
        i = i->next;
        j = j->prev;
    }

    if(i->val != j->val) flag = true;

    if (flag)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    
    
    
    return 0;
}

// input -----> 10 20 30 40 20 10 -1

// input -----> 10 20 30 40 30 20 10 -1

// input ----> 10 20 30 30 20 10 -1