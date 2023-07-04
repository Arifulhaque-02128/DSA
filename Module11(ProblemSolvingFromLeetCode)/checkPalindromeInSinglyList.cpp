#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public : 
        int val;
        ListNode * next;
    ListNode (int val){
        this->val = val;
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
    tail->next = newNode;
    tail = newNode;
}

void displayLinkedList(ListNode *head){
    ListNode *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void reverseLinkedList(ListNode *&head, ListNode *curr){
    if(curr->next == NULL){
        head = curr;
        return;
    }
    reverseLinkedList(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;
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

    displayLinkedList(head);

    ListNode *newHead = NULL;
    ListNode *newTail = NULL;
    ListNode *tmp = head;
    while (tmp != NULL)
    {
        insertAtTail(newHead, newTail, tmp->val);
        tmp = tmp->next;
    }

    reverseLinkedList(newHead, newHead);

    bool flag = true;

    ListNode *tmp1 = head;
    ListNode *tmp2 = newHead;
    while (tmp1 != NULL)
    {
        if(tmp1->val != tmp2->val){
            flag = false;
            break;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    if(flag) cout<<"Palindrome"<<endl;
    else cout<<"Not Palindrome"<<endl;
    
    return 0;
}

// input ----> 1 2 3 4 5 -1
// input ----> 1 2 3 2 1 -1