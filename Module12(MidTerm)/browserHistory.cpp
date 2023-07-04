#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        string val;
        Node * prev;
        Node * next;
    Node (string val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, string val){
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


void displayList(Node *head){
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

Node *findCurrentNode(Node *head, Node *curr, string word){
    Node *tmp = head;
    while(tmp != NULL){
        if(tmp->val == word){
            cout<<tmp->val<<endl;
            return tmp;
        }
        tmp = tmp->next;
    }

    cout<<"Not Available"<<endl;
    return curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        string v; cin>>v;
        if(v == "end") break;
        insertAtTail(head, tail, v);
    }

    int n; cin>>n;
    Node *curr = head;
    for (int i = 0; i < n; i++)
    {
        string cmd; cin>>cmd;

        if(cmd == "visit"){
            string word; cin>>word;
            curr = findCurrentNode(head, curr, word);
        }
        else if(cmd == "prev"){

            if(curr->prev == NULL){
                cout<<"Not Available"<<endl;
                
            } else {
                cout<<curr->prev->val<<endl;
            }

            if(curr->prev != NULL){
                curr = curr->prev;
            }
        } 
        else if(cmd == "next"){
            if(curr->next == NULL){
                cout<<"Not Available"<<endl;
                
            } else {
                cout<<curr->next->val<<endl;
            }

            if(curr->next != NULL){
                curr = curr->next;
            }
        } 
    }
    
    return 0;
}



// input -----> facebook google phitron youtube twitter end
// 12
// visit phitron
// prev
// prev
// prev
// prev
// next
// visit twitter
// next
// next
// prev
// visit django
// prev