#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> freq(26, 0);
    string s; cin>>s;

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]-'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            cout<<char('a'+i)<< " : "<<freq[i]<<endl;
        }
        
    }
    
    
    
    return 0;
}


// input ----> regff