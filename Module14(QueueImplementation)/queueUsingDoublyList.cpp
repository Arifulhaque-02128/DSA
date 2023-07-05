#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int val;
        Node *prev;
        Node * next;
    Node (int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class MyQueue{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int len = 0;

        void push(int val){
            len++;
            Node *newNode = new Node(val);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                return;
            }
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        void pop(){
            len--;
            Node *deleteNode = head;
            head = head->next;
            if(head == NULL){
                tail = NULL;
                delete deleteNode;
                return;
            }
            head->prev = NULL;
            delete deleteNode;
        }

        int front(){
            return head->val;
        }

        int size(){
            return len;
        }

        bool empty(){
            if(len == 0) return true;
            else return false;
        }

};

int main()
{

    MyQueue q;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        q.push(val);
    }

    while (! q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    
    return 0;
}