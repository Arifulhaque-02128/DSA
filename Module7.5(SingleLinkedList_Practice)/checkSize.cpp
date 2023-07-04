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
        return;
    }

    tail->next = newNode;
    tail = newNode;
    
}

void printLinkedList(Node *head){
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    
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

    int size1 = sizeOfLinkedList(head);

    Node *head1 = NULL;
    Node *tail1 = NULL;
    int val1;
    while (true)
    {
        cin>>val1;
        if (val1 == -1) break;
        insertAtTail(head1, tail1, val1);
    }

    int size2 = sizeOfLinkedList(head1);

    if (size1 == size2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    
    return 0;
}



// input ---> 5 1 4 5 -1
// 5 1 4 -1


// // input ----> 2 1 5 3 4 9 -1
// 1 2 3 4 5 6 -1
