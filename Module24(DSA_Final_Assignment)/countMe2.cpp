#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n; cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        int maxNumber=INT_MIN;
        int maxCnt = 0;
        
        map<int, int> mp;
        for(int val:arr){
            mp[val]++;
            if(maxCnt <= mp[val]){
                if(maxCnt == mp[val]){
                    if(maxNumber < val){
                        maxNumber = val;
                    }
                }
                else {
                    maxNumber = val;
                    maxCnt = mp[val];
                }
            }
        }

        cout<<maxNumber<<" "<<maxCnt<<endl;
    }
    
    return 0;
}



// input ----> 4
// 10 -10 -5 -20
// 10
// 1
// 2
// 2
// 2
// 2
// 0 10
// 1
// 2
// 0 20
// 1