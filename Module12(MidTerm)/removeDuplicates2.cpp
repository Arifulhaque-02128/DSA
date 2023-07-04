#include<bits/stdc++.h>
using namespace std;

int main()
{

    list<int> myList;
    int val;
    while (true)
    {
        cin>>val;
        if(val == -1) break;
        myList.push_back(val);
    }

    myList.sort();
    myList.unique();
    
    for(int n:myList){
        cout<<n<<" ";
    }
    
    return 0;
}


// input ----> 2 2 2 2 -1

// input ----> 1 2 1 3 2 4 2 1 3 -1

// input ----> 10 4 2 1 5 6 -1

// input ----> 5 4 3 5 4 2 5 3 2 4 5 1 2 3 4 5 -1

// input ----> 4 3 5 4 2 3 2 4 1 2 3 4 -1