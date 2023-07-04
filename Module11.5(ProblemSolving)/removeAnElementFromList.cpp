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

ListNode *removeElement(ListNode *&head, int val){

    if(head == NULL) return head;
    
    while(head->val == val){
        ListNode *deleteNode = head;
        head = head->next;
        delete deleteNode;
    }

    ListNode *tmp = head;
    while (tmp != NULL)
    {
        
        if(tmp->next->val == val){
            ListNode *deleteNode = tmp->next;
            tmp->next = tmp->next->next;
            delete deleteNode;
        }
        if(tmp->next == NULL) break;
        else if(tmp->next->val != val) tmp = tmp->next;
    }
    
    return head;
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

    int v; cin>>v;

    ListNode *newHead = removeElement(head, v);
    displayList(newHead);
    
    return 0;
}