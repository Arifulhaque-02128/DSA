#include<bits/stdc++.h>
using namespace std;

class MyLine{
    public:
        int len = 0;

        list<string> l;

        void push(string name){
            len++;
            l.push_back(name);
        }
        void pop(){
            len--;
            l.pop_front();
        }
        string front(){
            return l.front();
        }

        int size(){
            return len;
        }

        bool empty(){
            return l.empty();
        }

};

int main()
{
    int n; cin>>n;
    MyLine line;
    for (int i = 0; i < n; i++)
    {
        int cmd;
        cin>>cmd;

        if(cmd == 0){
            string name; cin>>name;
            line.push(name);
        }
        else if(cmd == 1){
            if(line.empty()){
                cout<<"Invalid"<<endl;
            } else {
                cout<<line.front()<<endl;
                line.pop();
            }
        }
    }
    

    return 0;
}

// input -----> 5
// 0 rahim
// 0 karim
// 1
// 0 sakib
// 1



// input ----> 8
// 1
// 0 embappe
// 0 neymar
// 1 
// 1
// 0 messi
// 1
// 1



// input ----> 6
// 0 embappe
// 0 embappe
// 1 
// 1
// 0 messi
// 1