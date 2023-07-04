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

ListNode *swappingNodes(ListNode *head, int front, int end){
    ListNode *tmp1 = head;
    ListNode *tmp2 = head;

    for (int i = 0; i < front; i++)
    {
        tmp1 = tmp1->next;
    }

    for (int j = 0; j < end; j++)
    {
        tmp2 = tmp2->next;
    }

    cout<<tmp1->val<<" "<<tmp2->val<<endl;

    swap(tmp1->val, tmp2->val);

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

    int n; cin>>n;

    int front = n-1;
    int end = findSize(head) - n;
    cout<<front<<" "<<end<<endl;

    ListNode *newHead = swappingNodes(head, front, end);

    displayList(newHead);
    
    return 0;
}


// input -----> 1 1 2 3 2 4 5 1 -1
// 3