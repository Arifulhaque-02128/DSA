#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int back = 0; int front = n-1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(back == front){
                if (i==j)
                {
                    cout<<"X";
                } else {
                    cout<<" ";
                }
                
            } else if (j==back)
            {
                cout<<"\\";
            } else if (j==front){
                cout<<"/";
            } else {
                cout<<" ";
            }
        }
        
        cout<<endl;

        back ++;
        front --;
    }
    
    return 0;
}


// input ----> 7