#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    if (a<b)
    {
        return true;
    } else {
        return false;
    }
    
}

int main()
{
    int n,m; cin>>n>>m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin>>x;

        int left = 0;
        int right = v.size() -1;

        int mid = (left + right)/2;
        while (left<=right)
        {
            if (x == v[mid])
            {
                cout<<"found"<<endl;
                break;
            } else if (x > v[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout<<"not found"<<endl;
    }
    
    
    
    return 0;
}