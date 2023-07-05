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

    stack<int> tempSt;
    while(!q.empty()){
        tempSt.push(q.front());
        q.pop();
    }

    queue<int> newQ;
    while(!tempSt.empty()){
        int v = tempSt.top();
        newQ.push(tempSt.top());
        tempSt.pop();
    }
    
    while (!newQ.empty())
    {
        cout<<newQ.front()<<" ";
        newQ.pop();
    }
    
    return 0;
}

// input ---> 5
// 10 20 30 40 50