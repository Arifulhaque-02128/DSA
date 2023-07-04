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
void reverseLinkedList(ListNode *&head, ListNode *curr ){
    if(curr->next == NULL) {
        head = curr;
        return;
    }
    reverseLinkedList(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;

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

    reverseLinkedList(head, head);
    displayLinkedList(head);

    return 0;
}


// input ----> 1 2 3 4 5 -1