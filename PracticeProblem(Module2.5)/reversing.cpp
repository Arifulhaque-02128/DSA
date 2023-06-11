#include<bits/stdc++.h>
using namespace std;




int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    reverse(a.begin(), a.end());
    for(int val : a){
        cout<<val<< " ";
    }
    
    return 0;
}


// input ---> 4
// 5 1 3 2
