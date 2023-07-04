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

void insert_to_tail(Node *&head, int val){
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    } else {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    
}

int count_size(Node *head){
    int cnt = 0;
    Node *temp = head;
    cout<<"Linked List : ";
    while (temp != NULL)
    {
        cnt++;
        cout<<temp->val<<" ";
        temp = temp->next;
    }

    return cnt;
    
}

int main()
{

    Node * head = NULL;

    int val;
    while (true)
    {
        cin>>val;
        if (val == -1)
        {
            break;
        }

        insert_to_tail(head, val);
        
    }

    int size = count_size(head);
    cout<<endl;
    cout<<size<<endl;
    
    
    return 0;
}