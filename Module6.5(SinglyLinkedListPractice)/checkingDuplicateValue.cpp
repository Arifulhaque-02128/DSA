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

void insert_to_tail(Node *&head, int val){
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    } else {
        Node * temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool checkingDuplicate(Node *head){
    int flag = false;
    Node *temp = head;
    while (temp != NULL)
    {
        int currentValue = temp->val;
        Node *tmpNode = temp->next;
        while (tmpNode != NULL)
        {
            int val = tmpNode->val;
            if (val == currentValue)
            {
                flag = true;
                break;
            } else {
                tmpNode = tmpNode->next;
            }
        }
        
        temp = temp->next;
    }

    return flag;
    
}

int main()
{

    Node *head = NULL;
    int val;
    while (true)
    {
        cin>>val;
        if(val == -1) break;
        insert_to_tail(head, val);
    }

    bool flag = checkingDuplicate(head);

    if (flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}