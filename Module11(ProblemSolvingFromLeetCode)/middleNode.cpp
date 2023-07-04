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

int findSize(ListNode *head){
    ListNode *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

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

ListNode * findMiddleNode(ListNode *head){
    int size = findSize(head);
    ListNode *tmp = head;
    for (int i = 0; i < (size/2); i++)
    {
        tmp = tmp->next;
    }
    return tmp;
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

    ListNode *midNode = findMiddleNode(head);
    cout<<midNode->val<<endl;

    return 0;
}


// input -----> 10 20 30 40 50 60 -1
// input -----> 10 20 30 40 50 -1