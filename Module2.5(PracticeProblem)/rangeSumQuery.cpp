#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin>>n>>m;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    vector<long long> prefixSum(n);
    prefixSum[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i-1] + v[i];
    }
    

    for (int i = 0; i < m; i++)
    {
        int l, r; cin>>l>>r;
        long long sum = prefixSum[r-1];
        if (l>1)
        {
            sum = sum - prefixSum[l-2];
        }
        
        cout<<sum<<endl;
    }
    
    
    
    return 0;
}


// input ----> 6 3
// 6 4 2 7 2 7
// 1 3
// 3 6
// 1 6
