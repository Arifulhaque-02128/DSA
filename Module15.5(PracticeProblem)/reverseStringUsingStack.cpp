#include<bits/stdc++.h>
using namespace std;

string reverseString(string &s){
    stack<char> st;
    for(char ch:s){
        st.push(ch);
    }

    string newStr = "";
    while (!st.empty())
    {
        newStr = newStr+st.top();
        st.pop();
    }

    return newStr;
}

int main()
{
    string str; cin>>str;
    string rev = reverseString(str);

    cout<<rev<<endl;

    return 0;
}


// input ----> ariful