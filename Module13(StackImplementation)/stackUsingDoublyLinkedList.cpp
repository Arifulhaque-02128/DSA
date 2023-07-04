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

class myStack{
    public: 
        Node *head = NULL;
        Node *tail = NULL;
        int len = 0;
        void push(int val){
            len++;
            Node *newNode = new Node (val);
            if(head == NULL){
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
            Node *deleteNode = tail;
            tail = tail->prev;

            if(tail == NULL) head = NULL;
            else tail->next = NULL;

            delete deleteNode;
        }

        int top(){
            return tail->val;
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

    myStack st;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        st.push(val);
    }

    while (! st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}


// input ----> 5
// 10 20 30 40 50