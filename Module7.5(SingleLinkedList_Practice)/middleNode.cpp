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
    }
    tail->next = newNode;
    tail = newNode;
}

int sizeOfLinkedList(Node *head){
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void findMidNode(Node *head, int pos, int quantity){
    Node *tmp = head;
    for (int i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }

    if (quantity == 1)
    {
        cout<<tmp->val;
    }
    else
    {
        cout<<tmp->val<<" "<<tmp->next->val;
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

    int size = sizeOfLinkedList(head);

    if (size%2 != 0)
    {
        int mid = (size-1)/2;
        findMidNode(head, mid, 1);
    }
    else
    {
        int mid = (size-2)/2;
        findMidNode(head, mid, 2);
    }
    
    
    return 0;
}



// input ---> 2 4 6 8 10 -1

// input ---> 1 2 3 4 5 6 -1