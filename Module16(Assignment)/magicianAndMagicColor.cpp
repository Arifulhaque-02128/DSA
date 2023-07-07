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
    int t; cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n; cin>>n;
        MyStack st;

        for (int j = 0; j < n; j++)
        {
            char ch; cin>>ch;
            if(st.empty()){
                st.push(ch);
            } else {
                if(st.top() == 'R'){
                    if(ch == 'B'){
                        st.pop();
                        if(st.top() == 'P'){
                            st.pop();
                        } else {
                            st.push('P');
                        }
                    } 
                    else if(ch == 'G'){
                        st.pop();
                        if(st.top() == 'Y'){
                            st.pop();
                        } else {
                            st.push('Y');
                        }
                    }
                    else if(ch == 'R'){
                        st.pop();
                    }
                }

                else if(st.top() == 'G'){
                    if(ch == 'B'){
                        st.pop();
                        if(st.top() == 'C'){
                            st.pop();
                        } else {
                            st.push('C');
                        }
                    } 
                    else if(ch == 'R'){
                        st.pop();
                        if(st.top() == 'Y'){
                            st.pop();
                        } else {
                            st.push('Y');
                        }
                    }
                    else if(ch == 'G'){
                        st.pop();
                    }
                }

                else if(st.top() == 'B'){
                    if(ch == 'R'){
                        st.pop();
                        if(st.top() == 'P'){
                            st.pop();
                        } else {
                            st.push('P');
                        }
                    } 
                    else if(ch == 'G'){
                        st.pop();
                        if(st.top() == 'C'){
                            st.pop();
                        } else {
                            st.push('C');
                        }
                    }
                    else if(ch == 'B'){
                        st.pop();
                    }
                }

                else {
                    st.push(ch);
                }
            }
        }

        string s = "";

        while(!st.empty()){
            s = st.top()+s;
            st.pop();
        }
        cout<<s<<endl;
    }
    
    
    return 0;
}


// input ----> 2
// 3
// RBG
// 4
// RGBB