#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n; cin>>n;
        list<int> l;
        for (int i = 0; i < n; i++)
        {
            int val; cin>>val;
            l.push_back(val);
        }

        l.sort(greater<int>());
        l.unique();
        
        for(int item:l){
            cout<<item<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}


// input ----> 4
// 5
// 20 10 40 50 30
// 10
// 10 20 40 20 10 30 50 10 20 40
// 5
// 20 20 20 20 20
// 4
// 10 30 10 30