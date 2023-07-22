#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp.insert({"Asif", 92});
    mp.insert({"Arif", 87});
    mp.insert({"Abir", 91});
    mp.insert({"Akib", 0});

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    if(mp.count("Asif")){
        cout<<"Asif ---> "<<mp["Asif"]<<endl;
    }

    if(mp.count("Akib")){
        cout<<"Akib ---> "<<mp["Akib"]<<endl;
    }

    if(mp.count("Ashik")){
        cout<<"Ashik ---> "<<mp["Ashik"]<<endl;
    }

    return 0;
}