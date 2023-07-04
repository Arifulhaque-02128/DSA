#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n; cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    bool flag = false;
    for(int i=0; i<n; i++){
        auto it = find(i+(arr.begin()+1), arr.end(), arr[i]);
        if (it != arr.end())
        {
            flag = true;
            break;
        }
        
    }

    if (flag)
    {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}


// input ----> 5 
// 10 20 30 20 50