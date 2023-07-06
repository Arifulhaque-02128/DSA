#include<bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t){
    stack<char> st1;
    for(char ch:s){
        if(ch == '#'){
            if(! st1.empty()) st1.pop();
        } else{
            st1.push(ch);
        }
    }

    stack<char> st2;
    for(char ch:t){
        if(ch == '#'){
            if(!st2.empty()) st2.pop();
        } else {
            st2.push(ch);
        }
    }

    if(st1.size() != st2.size()){
        return false;
    } else {
        while (!st1.empty())
        {
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
}

int main()
{

    string s1, s2; cin>>s1>>s2;

    bool result = backspaceCompare(s1, s2);

    if(result) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    
    return 0;
}


// input ----> ab#c
// ad#c


// input ----> ab##
// c#d#

// input -----> a#c
//b 