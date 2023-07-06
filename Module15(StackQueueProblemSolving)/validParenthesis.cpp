#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for (char ch:s)
    {
        if((ch == '(') || (ch=='{') || (ch == '[')){
            st.push(ch);
        } else {
            if(st.empty()){
                return false;
            } else {
                if(ch == ')' && st.top() == '('){
                    st.pop();
                }
                else if(ch == '}' && st.top() == '{'){
                    st.pop();
                }
                else if(ch == ']' && st.top() == '['){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return st.empty();
    
}

int main()
{

    string str; cin>>str;
    bool result = isValid(str);

    if(result) cout<<"Valid"<<endl;
    else cout<<"Not Valid"<<endl;
    
    return 0;
}


// input -----> {([]})
// input ----> {
// input -----> ([])