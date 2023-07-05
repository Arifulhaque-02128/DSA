#include<bits/stdc++.h>
using namespace std;
class myStack {
    public : 
        list<int> l;
        int len = 0;
        void push(int val){
            l.push_back(val);
        }
        void pop(){
            l.pop_back();
        }
        int top(){
            return l.back();
        }

        int size(){
            return l.size();
        }

        bool empty(){
            return l.empty();
        }
};
int main()
{
    myStack st1, st2;

    int n1; cin>>n1;
    for (int i = 0; i < n1; i++)
    {
        int val; cin>>val;
        st1.push(val);
    }

    int n2; cin>>n2;
    for (int i = 0; i < n2; i++)
    {
        int val; cin>>val;
        st2.push(val);
    }

    int size1 = st1.size();
    int size2 = st2.size();

    if (size1 != size2)
    {
        cout<<"NO"<<endl;
    } else {
        int flag = true;
        while (!st1.empty())
        {
            if(st1.top() != st2.top()){
                flag = false;
                break;
            } else{
                st1.pop();
                st2.pop();
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
    }
    
    
    return 0;
}


// input -----> 5
// 10 20 30 40 50
// 5
// 10 20 30 40 50


// input ----> 5
// 10 20 30 40 50
// 4
// 10 20 30 40


// input -----> 5
// 10 20 30 40 50
// 5
// 50 40 30 20 10


