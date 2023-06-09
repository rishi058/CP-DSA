#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
vector<bool> is_prime(N,1);

int main()
{                     
        //   pre-computation
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<N; i++){
        if(is_prime[i]==true){
            for(int j=2*i; j<N; j+=i){      // n*(log(log(n))) time-complexity
                is_prime[j] = false;
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        if(is_prime[num]){cout<<"prime\n";}
        else{cout<<"Not Prime\n";}
    }
}

/*
to check a large no. is prime or not normal method takes too much
time , therfore this code based on seive algo is used..

Q queries given in each query a large no.(<1e7) is given 
check it is prime or not.
*/