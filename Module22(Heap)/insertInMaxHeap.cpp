#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {50, 40, 45, 30, 35, 42, 32, 25, 20, 10};
    int x; cin>>x;
    v.push_back(x);

    int currIdx = v.size() - 1;
    while (currIdx != 0)
    {
        int parentIdx = (currIdx - 1)/2;
        if(v[currIdx] > v[parentIdx]){
            swap(v[currIdx], v[parentIdx]);
        } else break;
        currIdx = parentIdx;
    }
    
    for(int val:v){
        cout<<val<<" ";
    }
    
    return 0;
}

// input ----> 12

// input ------> 41