#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int val;
        Node * prev;
        Node * next;
    Node (int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int findSize(Node *head){
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

bool checkSimilarity(Node *head1, Node *head2){
    Node *tmp1 = head1;
    Node *tmp2 = head2;
    bool flag = false;
    while (tmp1 != NULL)
    {
        if(tmp1->val != tmp2->val) {
            flag = true;
            break;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return flag;
}

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;
    int val1;
    while (true)
    {
        cin>>val1;
        if(val1 == -1) break;
        insertAtTail(head1, tail1, val1);
    }


    Node *head2 = NULL;
    Node *tail2 = NULL;
    int val2;
    while (true)
    {
        cin>>val2;
        if(val2 == -1) break;
        insertAtTail(head2, tail2, val2);
    }

    int size1 = findSize(head1);
    int size2 = findSize(head2);

    if(size1 == size2){
        if (checkSimilarity(head1, head2))
        {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
        
    } else {
        cout<<"NO"<<endl;
    }


    
    
    return 0;
}