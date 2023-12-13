#include <bits/stdc++.h>
using namespace std;

map<int,int> primeFact(int n) { // Upgraded version..
    map<int,int> mapp;

    while(n % 2 == 0){
        mapp[2]++;
        n = n/2;
    }

    while(n%3==0){
        mapp[3]++;
        n/=3;
    }

    for(int i = 5; i*i<=n; i += 6){
        if(n%i==0){
            while(n % i == 0){
                mapp[i]++;
                n = n/i;
            }
        }
        if(n%(i+2)==0){
            while(n % (i+2) == 0){
                mapp[i+2]++;
                n = n/(i+2);
            }
        }
        
    }

    if(n>2){mapp[n]++;}

    return mapp;
}

map<int,int> primeFact2(int n) { // old version
    map<int,int> mapp;

    while(n % 2 == 0){
        mapp[2]++;
        n = n/2;
    }

    for(int i = 3; i*i<=n; i += 2){
        while(n % i == 0){
            mapp[i]++;
            n = n/i;
        }
    }

    if(n>2){mapp[n]++;}

    return mapp;
}

int main()
{
    int n; cin>>n;
    map<int,int> mapp = primeFact(98);

    for(auto x : mapp){
        cout<<x.first<<":"<<x.second<<"\n";
    }
}

