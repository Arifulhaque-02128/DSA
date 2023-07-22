#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    while (true)
    {
        int c; cin>>c;
        if(c == 0) {
            int val; cin>>val;
            pq.push(val);
        }

        else if(c == 1){
            pq.pop();
        }

        else if(c == 2){
            cout<<"top : "<<pq.top()<<endl;
        }

        else break;
    }

    return 0;
}


// input ----> 0 10
// 0 20
// 0 5
// 2 
// 1 
// 2
// 1
// 2
// 3