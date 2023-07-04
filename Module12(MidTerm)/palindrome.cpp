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

void reverse(Node *&head, Node *curr){
    if(curr->next == NULL){
        head = curr;
        return;
    }
    reverse(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;
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

    Node *newHead = NULL;
    Node *newTail = NULL;
    Node *tmp = head;
    while (tmp != NULL)
    {
        insertAtTail(newHead, newTail, tmp->val);
        tmp = tmp->next;
    }

    reverse(newHead, newHead);

    bool flag = true;

    Node *tmp1 = head;
    Node *tmp2 = newHead;
    while (tmp1 != NULL)
    {
        if(tmp1->val != tmp2->val){
            flag = false;
            break;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}