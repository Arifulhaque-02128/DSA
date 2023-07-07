#include<bits/stdc++.h>
using namespace std;

class MyStack{
    public:
        list<char> l;
        void push(char ch){
            l.push_back(ch);
        }
        void pop(){
            l.pop_back();
        }
        char top(){
            return l.back();
        }

        bool empty(){
            return l.empty();
        }
};

int main()
{
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        MyStack st;
        string str; cin>>str;
        for(char c:str){
            if(st.empty()){
                st.push(c);
            } else {
                if(st.top() == 'A' && c == 'B'){
                    st.pop();
                }
                else if(st.top() == 'B' && c == 'A'){
                    st.pop();
                }
                else {
                    st.push(c);
                }
            }
        }

        if(st.empty()){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
}


// input -----> 10
// AABB
// BABA
// BBAA
// ABAB
// AAAB
// ABBB
// ABBA
// BAABAB
// BBBAABA
// AAABABBABB