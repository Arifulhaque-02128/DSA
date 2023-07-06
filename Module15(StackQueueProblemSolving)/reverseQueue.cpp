#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        q.push(val);
    }

    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    return 0;
}

// input ---> 6
// 1 2 3 4 5 6


// input ----> 1
// 9


// input ----> 2
// 88 89