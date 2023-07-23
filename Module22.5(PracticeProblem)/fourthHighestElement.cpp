#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }


    int fourthLargest = INT_MIN;
    int sz = pq.size();
    for (int i = 0; i < sz; i++)
    {
        
        if(i == 3) {
            fourthLargest = pq.top();
            break;
        } else {
            pq.pop();
        }
    }


    cout<<fourthLargest<<endl;
    
    
    return 0;
}

// input ----> 5
// 3 5 1 3 1

// input --->4
// 9 9 9 9