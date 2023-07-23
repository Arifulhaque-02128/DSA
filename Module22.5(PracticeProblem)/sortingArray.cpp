#include<bits/stdc++.h>
using namespace std;

void insertToHeap(vector<int> &v, int val){
    v.push_back(val);
    int curr = v.size() -1;
    while (curr != 0)
    {
        int pIdx = (curr-1)/2;
        if(v[pIdx] > v[curr]){
            swap(v[pIdx], v[curr]);
            curr = pIdx;
        } else break;
    }
}

void deleteFromHeap(vector<int> &v){
    int curr = 0;
    v[curr] = v[v.size() -1];

    v.pop_back();

    while (true)
    {
        int leftIdx = (curr*2) + 1;
        int rightIdx = (curr*2) + 2;
        int lastIdx = v.size() - 1;

        if(leftIdx <= lastIdx && rightIdx <= lastIdx){
            if(v[leftIdx] < v[curr] && v[leftIdx] <= v[rightIdx]) {
                swap(v[leftIdx], v[curr]);
                curr = leftIdx;
            } 
            else if(v[rightIdx] < v[curr] && v[rightIdx] < v[leftIdx]){
                swap(v[rightIdx], v[curr]);
                curr = rightIdx;
            } else break;
        }

        else if(leftIdx <= lastIdx){
            if(v[leftIdx] < v[curr]) {
                swap(v[leftIdx], v[curr]);
                curr = leftIdx;
            } else break;
        }

        else if(rightIdx <= lastIdx){
            if(v[rightIdx] < v[curr]){
                swap(v[rightIdx], v[curr]);
                curr = rightIdx;
            } else break;
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
        insertToHeap(v, val);
    }

    vector<int> vec;
    while(v.size()){
        vec.push_back(v[0]);
        deleteFromHeap(v);
    }

    cout<<endl;

    for(int val:vec){
        cout<<val<<" ";
    }

    return 0;
}

// input ----> 4
// 5 2 3 1