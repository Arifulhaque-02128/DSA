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

ListNode *removeNthFromEnd(ListNode *&head, int pos){
    if (pos == 0)
    {
        ListNode *deleteNode = head;
        head = head->next;
        delete deleteNode;
    } else {
        ListNode *tmp = head;
        for (int i = 1; i < pos; i++)
        {
            tmp = tmp->next;
        }
        
        ListNode *deleteNode = tmp->next;
        tmp->next = tmp->next->next;
        delete deleteNode;
    }

    return head;
    
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

    int end; cin>>end;

    int pos = findSize(head) - end;
    cout<<pos<<endl;

    ListNode *newHead = removeNthFromEnd(head, pos);
    displayList(newHead);

    return 0;
}