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
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
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

void printMiddleNode (Node *head, int pos, int cnt){
    Node *tmp = head;
    for (int i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }

    if (cnt == 1)
    {
        cout<<tmp->val<<endl;
    } else {
        cout<<tmp->val<<" "<<tmp->next->val<<endl;
    }
    
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
    
    int len = findSize(head);
    // cout<<len<<endl;

    for (Node * i = head; i->next != NULL; i=i->next)
    {
        for (Node * j = i->next; j != NULL; j=j->next)
        {
            if(i->val < j->val) swap(i->val, j->val);
        }
        
    }
    
    
    if(len%2 == 1) {
        int mid = len/2;
        printMiddleNode(head, mid, 1);
    } else {
        int mid = len/2;
        printMiddleNode(head, mid-1, 2);
    }
    
    return 0;
}


// input ----> 20 10 40 30 50 -1

// input ----> 20 30 10 40 60 50 -1

// input ----> 726 -1

// input ----> 348 726 -1