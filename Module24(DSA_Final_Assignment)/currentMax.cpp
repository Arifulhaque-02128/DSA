#include<bits/stdc++.h>
using namespace std;

class Student {
    public : 
        string name;
        int roll;
        int marks;
    Student (string name, int roll, int marks){
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp{
    public:
        bool operator()(Student a, Student b){
            if(a.marks <= b.marks){
                if(a.marks == b.marks){
                    if(a.roll > b.roll) return true;
                    else return false;
                }
                else return true;
            }
            else return false;
        }
};

int main()
{
    int n; cin>>n;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin>>name>>roll>>marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }
    

    int m; cin>>m;
    for (int i = 0; i < m; i++)
    {
        int c; cin>>c;
        if(c == 0){
            string name;
            int roll, marks;
            cin>>name>>roll>>marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;

        }

        else if(c == 1){
            if(pq.size()) cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
            else cout<<"Empty"<<endl;
        }

        else if(c == 2){
            if(pq.size()){ 
                pq.pop();
                if(pq.size()){
                    cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
                }
                else cout<<"Empty"<<endl;
            }
            else cout<<"Empty"<<endl;
        }
    }
    
    return 0;
}


// input ----> 3
// akib 23 95
// jobbar 24 99
// ali 25 100
// 8
// 1
// 2
// 2
// 2
// 0 kabir 15 65
// 0 asif 55 65
// 2
// 0 tamim 35 65