#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        bool flag = true;

        for (int i = 1; i < n; i++)
        {
            if (v[i]<v[i-1])
            {
                flag = false;
                break;
            }
            
        }

        if (flag)
        {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}


// input ----> 3
// 5
// 2 4 6 7 10
// 8
// 1 100 101 120 120 121 1000 1000
// 4
// 100 1 102 12