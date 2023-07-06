#include<bits/stdc++.h>
using namespace std;

int getSum(stack<int> st){
    int sum = 0;
    while (!st.empty())
    {
        sum = sum + st.top();
        st.pop();
    }
    return sum;
}

int main()
{
    stack<int> st1;
    stack<int> st2;
    stack<int> st3;

    int n1; cin>>n1;
    for (int i = 0; i < n1; i++)
    {
        int val; cin>>val;
        st1.push(val);
    }

    int n2; cin>>n2;
    for (int i = 0; i < n2; i++)
    {
        int val; cin>>val;
        st2.push(val);
    }

    int n3; cin>>n3;
    for (int i = 0; i < n3; i++)
    {
        int val; cin>>val;
        st3.push(val);
    }

    int sum1 = getSum(st1);
    int sum2 = getSum(st2);
    int sum3 = getSum(st3);

    int maxSum;

    while (true)
    {
        if(sum1 == sum2 && sum2 == sum3) {
            maxSum = sum1;
            break;
        } else {
            if(sum1 >= sum2 && sum1 >= sum3){
                sum1 = sum1 - st1.top();
                st1.pop();
            }
            else if(sum2 >= sum1 && sum2 >= sum3){
                sum2 = sum2 - st2.top();
                st2.pop();
            }
            else if(sum3 >= sum1 && sum3 >= sum2){
                sum3 = sum3 - st3.top();
                st3.pop();
            }
        }
    }

    cout<<"MAX SUM : "<<maxSum<<endl;

    
    return 0;
}