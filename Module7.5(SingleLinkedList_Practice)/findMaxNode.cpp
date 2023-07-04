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
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }

    tail->next = newNode;
    tail = newNode;
}


int findMaxNode(Node *head){
    Node *tmp = head;
    int max = tmp->val;
    while (tmp != NULL)
    {

        if ((tmp->val) > max)
        {
            max = tmp->val;
        }
        tmp = tmp->next;
    }

    return max;
    
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
    
    int max = findMaxNode(head);

    cout<<max<<endl;
    
    return 0;
}


// input ---> 5 4 1 2 5 6 8 4 1 3 -1