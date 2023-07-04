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

int findMax(Node *head){
    Node *tmp = head;
    int max = tmp->val;
    
    while (tmp != NULL)
    {
        if(max < tmp->val){
            max = tmp->val;
        }
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    return max;
    
}

int findMin(Node *head){
    Node *tmp = head;
    int min = tmp->val;
    while (tmp != NULL)
    {
        if(min > tmp->val){
            min = tmp->val;
        }
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }

    return min;
    
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin>>val;
        if(val==-1) break;
        insertAtTail(head, tail, val);
    }

    int max = findMax(head);
    int min = findMin(head);

    cout<<max<<" "<<min<<endl;
    
    return 0;
}


// input ----> 2 4 1 5 3 6 -1
// input ----> 2 -1