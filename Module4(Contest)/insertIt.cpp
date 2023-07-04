#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int m; cin>>m;
    vector<int> w(m);
    for (int i = 0; i < m; i++)
    {
        cin>>w[i];  
    }

    int x; cin>>x;

    v.insert(v.begin()+x, w.begin(), w.end());

    for (int i = 0; i < (n+m); i++)
    {
        cout<<v[i]<< " ";
    }
    
    
    
    return 0;
}

// input -----> 5
// 2 3 4 5 6
// 3
// 10 20 30
// 3