#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

1. 1 << x ==> 2^x  [left shift]  0011 << 1 = 0110

2. x >> 1 ==> x/2  [right shift] 1100 >> 1 = 0110

3. Bitmask takes space of 2^n, 
   therefore if working with 1-D, make sure n ~ 23 [bcz 2^23 is 1e7]
   if working with multiple dimension make sure product of constraints does exceed the limit.
   Bitmask used to store state [e.g -> visited]

*/


void setNthBit(int& number, int& n){
   int mask = 1 << n;
   number = number | mask;
}

void unsetsetNthBit(int& number, int n){
   int mask = ~(1 << n);
   number = number & mask;
}

void flipNthBit(int& number, int n){
   int mask = 1 << n;
   number = number ^ mask;
}

bool isNthBitSet(int& number, int& n){
   int mask = 1 << n;
   return (number & mask) != 0;
}

void unsetLeftmostBit(int &num){
   num &= (-num);
}

void unsetRightmostBit(int &num) {
   num &= (num - 1);
}

int findLSB(int n){  
   if(n==0){ return 0;}
   int pos = 1;
   while(n){
      if(n&1){return pos;}
      n>>=1; pos++;
   }
   return pos;    
}

int findMSB(int n){
   int pos = 0;
   if(n==0){return -1; }
   while(n != 0){
      n >>= 1; pos++;
   }
   return pos - 1;
}

// __builtin_popcountll(x)  --> to find no. of set bits.
// __builtin_ctz(x)         --> Find the pos of LSB in x

bool isPower2(int x){
   return !(x&(x-1));
}

bool isEveryBitSet(int x){   // i.e x = pow(2,n) - 1;
   return !(x&(x+1));
}


int nextPow2(int x){         
   int z = ceil(log2(x));
   if(isPower2(x)){z++;}
   return 1<<z;
}

int prevPow2(int x){     
   int z = floor(log2(x));
   if(isPower2(x)){z--;}
   return 1<<z;
}

int32_t main()
{
   RISHI
   cout<<nextPow2(8);
}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝