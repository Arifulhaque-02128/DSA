#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        st.push(val);
    }
    for (int i = 0; i < m; i++)
    {
        int val; cin>>val;
        q.push(val);
    }

    list<int> l1;
    list<int> l2;

    while (!st.empty())
    {
        l1.push_back(st.top());
        st.pop();
    }
    
    while (!q.empty())
    {
        l2.push_back(q.front());
        q.pop();
    }

    bool flag = true;

    if(l1.size() != l2.size()){
        flag = false;
    } else {
        while (!l1.empty())
        {
            if(l1.back() != l2.back()){
                flag = false;
                break;
            }
            l1.pop_back();
            l2.pop_back();
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
    
    return 0;
}


// input ----> 5 5
// 10 20 30 40 50
// 50 40 30 20 10


// input ----> 4 4
// 10 20 30 40
// 10 20 30 40


// input ----> 5 4
// 10 20 30 40 50
// 50 40 30 20