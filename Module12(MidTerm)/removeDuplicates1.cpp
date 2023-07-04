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
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
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

    // sort
    for (Node * i = head; i->next != NULL; i=i->next)
    {
        for (Node * j = i->next; j != NULL; j=j->next)
        {
            if(i->val > j->val){
                swap(i->val, j->val);
            }
        }
    }

    // remove duplicate values

    Node *newHead = head;
    Node *tmp = newHead;
    while (tmp->next != NULL)
    {
        if(tmp->val == tmp->next->val){
            Node *deleteNode = tmp->next;
            tmp->next = tmp->next->next;
            delete deleteNode;
        }
        if(tmp->next == NULL) break;
        else if(tmp->val != tmp->next->val){
            tmp = tmp->next;
        }
    }

    displayList(newHead);
    
    return 0;
}

// input ----> 2 2 2 2 -1

// input ----> 1 2 1 3 2 4 2 1 3 -1

// input ----> 10 4 2 1 5 6 -1

// input ----> 5 4 3 5 4 2 5 3 2 4 5 1 2 3 4 5 -1

// input ----> 4 3 5 4 2 3 2 4 1 2 3 4 -1