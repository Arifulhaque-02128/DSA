#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 15, 20, 15, 20, 30};
    int x; cin>>x;
    v.push_back(x);

    int currIdx = v.size() - 1;
    while (currIdx != 0)
    {
        int parentIdx = (currIdx - 1)/2;
        if(v[currIdx] < v[parentIdx]){
            swap(v[currIdx], v[parentIdx]);
            currIdx = parentIdx;
        }
        else break;
    }

    for(int val:v){
        cout<<val<<" ";
    }
    
    return 0;
}

// input ----> 8
// inptut ----> 12