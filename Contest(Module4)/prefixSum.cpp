#include<bits/stdc++.h>
using namespace std;


bool cmp(long long a, long long b){
    if(a>b) return true;
    else return false;
}

int main()
{
    int n; cin>>n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    vector<long long> preSum(n);
    preSum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        long long sum = preSum[i-1] + v[i];
        preSum[i] = sum;
    }


    for (int i = n-1; i >= 0; i--)
    {
        cout<<preSum[i]<< " ";
    }
    
    
    
    return 0;
}