#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    vector<int> c(b);
    for(int val: a){
        c.push_back(val);
    }

    for(int val: c){
        cout<<val<<" ";
    }
    
    
    return 0;
}


// input ----> 2
// 1 2
// 3 4
