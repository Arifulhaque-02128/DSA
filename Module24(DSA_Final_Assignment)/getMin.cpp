#include<bits/stdc++.h>
using namespace std;

void insertValue(vector<int> &v, int x){
    v.push_back(x);
    int curr = v.size() - 1;
    while (curr != 0)
    {
        int pIdx = (curr - 1)/2;
        if(v[curr] < v[pIdx]){
            swap(v[curr], v[pIdx]);
            curr = pIdx;
        }
        else break;
    }
}


void deleteValue(vector<int> &v){
    int curr = 0;
    v[curr] = v[v.size() -1];
    v.pop_back();

    while (true)
    {
        int leftIdx = (curr*2) +1;
        int rightIdx = (curr*2) +2;
        int lastIdx = v.size() -1;

        if(leftIdx <= lastIdx && rightIdx <= lastIdx){
            if(v[leftIdx] < v[curr] && v[leftIdx] <= v[rightIdx]){
                swap(v[leftIdx], v[curr]);
                curr = leftIdx;
            }

            else if(v[rightIdx] < v[curr] && v[rightIdx] < v[leftIdx]){
                swap(v[rightIdx], v[curr]);
                curr = rightIdx;
            }

            else break;
        }

        else if(leftIdx <= lastIdx){
            if(v[leftIdx] < v[curr]){
                swap(v[leftIdx], v[curr]);
                curr = leftIdx;
            }

            break;
        }

        else if(rightIdx <= lastIdx){
            if(v[rightIdx] < v[curr]){
                swap(v[rightIdx], v[curr]);
                curr = rightIdx;
            }

            else break;
        }

        else break;
    }
    
}

int main()
{
    int n; cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int val; cin>>val;
        insertValue(v, val);
    }

    int m; cin>>m;
    for (int i = 0; i < m; i++)
    {
        int c; cin>>c;
        if(c == 0){
            int val; cin>>val;
            insertValue(v, val);
            cout<<v[0]<<endl;
        }

        else if(c == 1){
            if(v.size()) cout<<v[0]<<endl;
            else cout<<"Empty"<<endl;
        }

        else if(c == 2){
            if(v.size()){ 
                deleteValue(v);
                if(v.size()){
                    cout<<v[0]<<endl;
                }
                else cout<<"Empty"<<endl;
            }
            else cout<<"Empty"<<endl;
        }
    }
    
    return 0;
}


// input ----> 4
// 10 -10 -5 -20
// 10
// 1
// 2
// 2
// 2
// 2
// 0 10
// 1
// 2
// 0 20
// 1