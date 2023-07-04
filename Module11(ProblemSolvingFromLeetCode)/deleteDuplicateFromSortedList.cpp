#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public : 
        int val;
        ListNode * prev;
        ListNode * next;
    ListNode (int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtTail(ListNode *&head, ListNode *&tail, int val){
    ListNode *newNode = new ListNode(val);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

ListNode *deleteDuplicate(ListNode *head){
    if(head == NULL) return head;
    ListNode *tmp = head;
    while (tmp->next != NULL)
    {
        if(tmp->val == tmp->next->val){
            tmp->next = tmp->next->next;
        }
        if(tmp->next == NULL) break;
        else if(tmp->val != tmp->next->val){
            tmp = tmp->next;
        }
    }
    return head;
}

void displayLinkedList(ListNode *head){
    ListNode *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
}

int main()
{

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int val;
    while(true){
        cin>>val;
        if(val == -1) break;
        insertAtTail(head, tail, val);
    }

    ListNode *newHead = deleteDuplicate(head);
    displayLinkedList(newHead);
    
    return 0;
}


// input -----> 1 1 2 3 3 3 4 5 5 -1