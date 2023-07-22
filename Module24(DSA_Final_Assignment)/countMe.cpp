#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        string s;
        getline(cin, s);
        string word;
        stringstream ss(s);

        map<string, int> mp;

        string maxWord;
        int maxCnt = 0;

        while (ss>>word)
        {
            mp[word]++;
            if(mp[word] > maxCnt){
                maxWord = word;
                maxCnt = mp[word];
            }
        }

        cout<<maxWord<<" "<<maxCnt<<endl;
    }
    
    return 0;
}


// input -----> 2
// ratul piyush fohad shuvo rafi piyush fohad ratul 
// jony jony yes papa eating sugar no papa telling lies no papa open your mouth ha ha ha