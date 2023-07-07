#include<bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k){

    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    queue<int> newQ;
    while (!st.empty())
    {
        newQ.push(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        newQ.push(q.front());
        q.pop();
    }

    return newQ;
    
}

int main()
{
    queue<int> q;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        q.push(val);
    }

    int k; cin>>k;

    queue<int> newQ = reverseElements(q, k);

    while (!newQ.empty())
    {
        cout<<newQ.front()<<" ";
        newQ.pop();
    }
    
    
    return 0;
}