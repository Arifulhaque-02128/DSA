#include<bits/stdc++.h>
using namespace std;

void insertInMinHeap(vector<int> &v, int val){
    v.push_back(val);
    int currIdx = v.size() -1;
    while (currIdx)
    {
        int parentIdx = (currIdx -1)/2;
        if(v[currIdx] < v[parentIdx]){
            swap(v[currIdx], v[parentIdx]);
            currIdx = parentIdx;
        }
        else break;
    }
    
}

void deleteFromMinHeap(vector<int> &v){
    int currIdx = 0;
    v[currIdx] = v[v.size()-1];
    v.pop_back();

    while (true)
    {
        int leftIdx = (currIdx*2) + 1;
        int rightIdx = (currIdx*2) + 2;
        int lastIdx = v.size() - 1;

        if(leftIdx <= lastIdx && rightIdx <= lastIdx){
            if(v[leftIdx] < v[currIdx] && v[leftIdx] <= v[rightIdx]){
                swap(v[leftIdx], v[currIdx]);
                currIdx = leftIdx;
            }
            else if(v[rightIdx] < v[currIdx] && v[rightIdx] < v[leftIdx]){
                swap(v[rightIdx], v[currIdx]);
                currIdx = rightIdx;
            } else break;
        }

        else if(leftIdx <= lastIdx){
            if(v[leftIdx] < v[currIdx]){
                swap(v[leftIdx], v[currIdx]);
                currIdx = leftIdx;
            } else break;
        }

        else if(rightIdx <= lastIdx){
            if(v[rightIdx] < v[currIdx]){
                swap(v[rightIdx], v[currIdx]);
                currIdx = rightIdx;
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
        insertInMinHeap(v, val);
    }

    cout<<"Before Deletion : ";
    for(int val: v){
        cout<<val<<" ";
    }
    cout<<endl;

    deleteFromMinHeap(v);

    cout<<"After Deletion : ";
    for(int val:v){
        cout<<val<<" ";
    }
    
    return 0;
}


// input ----> 10
// 50 40 42 30 35 45 32 25 20 10