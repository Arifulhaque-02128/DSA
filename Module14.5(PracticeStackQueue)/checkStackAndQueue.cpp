#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        st.push(val);
    }

    int m; cin>>m;
    for (int i = 0; i < m; i++)
    {
        int val; cin>>val;
        q.push(val);
    }

    int stackSize = st.size();
    int queueSize = q.size();

    if (stackSize != queueSize)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        int flag = true;
        while (!st.empty())
        {
            if(st.top() != q.front()){
                flag = false;
                break;
            } else {
                st.pop();
                q.pop();
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