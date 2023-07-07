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

class MyStack{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int len = 0;

        int getSize(){
            return len;
        }

        bool isEmpty(){
            if(len==0) return true;
            else return false;
        }

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
            if(head == NULL) return;

            len--;
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head == NULL) tail = NULL;
        }

        int getTop(){
            if(head == NULL) return -1;
            return head->val;
        }
};

int main()
{

    MyStack st;
    st.push(5);
    st.push(4);

    cout<<"size : "<<st.getSize()<<endl;
    cout<<"is empty: "<<st.isEmpty()<<endl;

    st.pop();
    cout<<"top : "<<st.getTop()<<endl;

    cout<<"size : "<<st.getSize()<<endl;
    cout<<"is empty: "<<st.isEmpty()<<endl;
    
    return 0;
}