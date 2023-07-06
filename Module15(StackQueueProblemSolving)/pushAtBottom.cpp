#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        st.push(val);
    }

    int x; cin>>x;

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

    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
    
    
    return 0;
}


// input ----> 4
// 7 1 4 5
// 9