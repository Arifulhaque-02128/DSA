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
    ListNode *newNode = new ListNode (val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void displayList(ListNode *head){
    ListNode *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
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
    displayList(head);

    ListNode *newHead = NULL;
    ListNode *newTail = NULL;

    int sum = 0;
    ListNode *tmp = head->next;
    while(tmp != NULL){
        if(tmp->val != 0){
            sum = sum + tmp->val;
            tmp = tmp->next;
            continue;
        }
        insertAtTail(newHead, newTail, sum);
        sum = 0;
        tmp = tmp->next;
    }

    displayList(newHead);
    
    return 0;
}

// input ----> 0 3 1 0 4 5 2 0 1 9 8 6 0 -1