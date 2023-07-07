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

class MinStack{
    public:
        Node *head = NULL;
		Node *tail = NULL;

		Node *minHead = NULL;
		Node *minTail = NULL;
		
		int len = 0;

        void push(int val)
		{
			// Write your code here.
			len++;
			Node *newNode = new Node(val);
			Node *newMinNode = new Node(val);
			if(head == NULL){
				head = newNode;
				tail = newNode;
			} else {
				newNode->next = head;
				head = newNode;
			}

			if(minHead == NULL){
				minHead = newMinNode;
				minTail = newMinNode;
			} else {
				if(newMinNode->val <= minHead->val){
					newMinNode->next = minHead;
					minHead = newMinNode;
				}
			}
			
		}

        int pop()
		{
			// Write your code here.
			if(head == NULL) return -1;

			len--;

			Node *deleteNode = head;

            int data = head->val;
            if(data == minHead->val){
                Node *deleteMinNode = minHead;
                minHead = minHead->next;
                delete deleteMinNode;
                if(minHead == NULL) minTail = NULL;
            }

            head = head->next;
			delete deleteNode;
			if(head == NULL) tail = NULL;

			return data;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(len==0) return -1;
			
			return head->val;

		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(minHead == NULL) return -1;
			return minHead->val;
			
		}
};

int main()
{

    MinStack st;
    st.push(3);
    st.push(2);
    st.push(1);

    int min = st.getMin();
    cout<<min<<endl;

    int r = st.pop();
    cout<<r<<endl;

    int t = st.top();
    cout<<t<<endl;

    cout<<st.getMin()<<endl;
    cout<<st.pop()<<endl;

    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;

    cout<<st.top()<<endl;
    cout<<st.getMin()<<endl;
    
    return 0;
}