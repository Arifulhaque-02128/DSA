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

int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);

    head->next = a;
    a->next = b;
    b->next = c;

    cout<<"Head : "<< head->val<<endl;
    cout<<"a : "<< head->next->val<<endl;
    cout<<"b : "<< head->next->next->val<<endl;
    cout<<"c : "<< b->next->val<<endl;
    return 0;
}