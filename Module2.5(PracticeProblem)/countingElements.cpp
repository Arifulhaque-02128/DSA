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
    
    int cnt= 0;

    for (int i = 0; i < n; i++)
    {
        auto it = find(v.begin(), v.end(), v[i]+1);
        if(it != v.end()){
            cnt++;
        }
        
    }

    cout<<cnt<<endl;
    
    
    return 0;
}



// input -----> 3
// 4 4 5


// input -----> 3
// 1 2 3


// input ----> 8
// 1 1 3 3 5 5 7 7


// input ----> 6
// 1 3 2 3 5 0

