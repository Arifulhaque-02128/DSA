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
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int checkSimilarity(Node *head1, Node *head2){
    int flag = 0;
    Node *tmp1 = head1;
    Node *tmp2 = head2;

    while (tmp1 != NULL || tmp2 != NULL)
    {
        if (tmp1 == NULL || tmp2 == NULL)
        {
            flag = 1;
            break;
        }
        
        if(tmp1->val != tmp2->val ){
            flag = 1;
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
    while(true){
        cin>>val1;
        if(val1 == -1) break;
        insertAtTail(head1, tail1, val1);
    }

    Node *head2 = NULL;
    Node *tail2 = NULL;
    int val2;
    while(true){
        cin>>val2;
        if(val2 == -1) break;
        insertAtTail(head2, tail2, val2);
    }

    int flag = checkSimilarity(head1, head2);

    if (flag == 0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}


// input ---> 10 20 30 40 -1
// 10 20 30 40 -1


// input ----> 10 20 30 40 -1
// 10 20 30 -1


// input -----> 10 20 30 40 -1
// 10 20 30 50 -1