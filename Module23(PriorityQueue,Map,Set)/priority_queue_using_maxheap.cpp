#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    while (true)
    {
        int c; cin>>c;

        // insert in priority queue
        if(c == 0){
            int val; cin>>val;
            pq.push(val);
        }

        // delete from priority queue
        else if(c == 1) {
            pq.pop();
        }

        // access top element of priority queue
        else if(c == 2) {
            cout<<"top : "<<pq.top()<<endl;
        }

        // exit
        else break;
    }
    
    return 0;
}


// input -----> 0 10
// 0 20
// 0 5
// 2 
// 1 
// 2
// 1
// 2
// 3