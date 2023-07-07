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

class MyStack {

    public:
        Node *head = NULL;
        Node *tail = NULL;
        int len = 0;

        void push(int val){
            len++;
            Node *newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            newNode->next = head;
            head = newNode;
        }

        void pop(){
            len--;
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head==NULL) tail = NULL;
        }

        int top(){
            return head->val;
        }

        int size(){
            return len;
        }

        int empty(){
            if(len==0) return true;
            else return false;
        }

};


class MyQueue {

    public:
        Node *head = NULL;
        Node *tail = NULL;
        int len = 0;

        void push(int val){
            len++;
            Node *newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }

        void pop(){
            len--;
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head==NULL) tail = NULL;
        }

        int front(){
            return head->val;
        }

        int size(){
            return len;
        }

        int empty(){
            if(len==0) return true;
            else return false;
        }

};


int main()
{
    MyStack st;
    MyQueue q;
    int n, m; cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        st.push(val);
    }

    for (int i = 0; i < m; i++)
    {
        int val; cin>>val;
        q.push(val);
    }
    
    list<int> l1;
    list<int> l2;

    while (!st.empty())
    {
        l1.push_back(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        l2.push_back(q.front());
        q.pop();
    }
    


    bool flag = true;

    if(l1.size() != l2.size()){
        flag = false;
    } else {
        while (!l1.empty())
        {
            if(l1.back() != l2.back()){
                flag = false;
                break;
            }
            l1.pop_back();
            l2.pop_back();
        }
    }

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


// input ----> 5 5
// 10 20 30 40 50
// 50 40 30 20 10


// input ----> 4 4
// 10 20 30 40
// 10 20 30 40


// input ----> 5 4
// 10 20 30 40 50
// 50 40 30 20