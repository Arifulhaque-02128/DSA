#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        s.insert(val); // insertion = O(logN)
    }

    // sorted and no duplicate value 
    cout<<endl<<"Sorted values : "<<endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout<<*it<<endl;
    }

    // searching
    cout<<endl<<"Searching : "<<endl;
    if(s.count(50)){
        cout<<"50 is present"<<endl;
    } else {
        cout<<"50 is not present"<<endl;
    }

    if(s.count(100)){
        cout<<"100 is present"<<endl;
    } else {
        cout<<"100 is not present"<<endl;
    }
    
    return 0;
}