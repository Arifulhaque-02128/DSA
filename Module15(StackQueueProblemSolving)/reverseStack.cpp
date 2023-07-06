#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &st){
    if(st.empty()) return;

    int x = st.top();
    st.pop();

    reverseStack(st);

    stack<int> newSt;
    while (!st.empty())
    {
        newSt.push(st.top());
        st.pop();
    }
    newSt.push(x);
    while (!newSt.empty())
    {
        st.push(newSt.top());
        newSt.pop();
    }
    
}

int main()
{

    stack<int> st;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        st.push(val);
    }

    reverseStack(st);

    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}


// input ----> 5
// 5 4 3 2 1