#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

void change(string &dir){
  if(dir=="DL"){ dir = "DR"; }
  else if(dir=="DR"){ dir = "DL"; }
  else if(dir=="UL"){ dir = "UR"; }
  else{ dir = "UL"; }
}

bool check(int a, int b, int c, int d, string dir){
  int x = c-a;
  int y = d-b;  // dest - inital...
  if(abs(x)!=abs(y)){return false;}
  else if(x>0 && y<0 && dir=="DL"){return true;}
  else if(x<0 && y>0 && dir=="UR"){return true;}
  else if(x>0 && y>0 && dir=="DR"){return true;}
  else if(x<0 && y<0 && dir=="UL"){return true;}
  else{return false;}
}

void placeToCorner(int &a, int &b, int n, int m, string dir){
  if(dir=="DL"){
    int x = min(a-1, m-b);
    a += x;
    b -= x;
  }
  else if(dir=="DR"){
    int x = min(n-a, m-b);
    a += x;
    b += x;
  }
  else if(dir=="UL"){
    int x = min(a-1, b-1);
    a -= x;
    b -=x;
  }
  else{
    int x = min(n-a, b-1);
    a -= x;
    b += x;
  }
}

int32_t main()
{
  RISHI
  int t; cin>>t;
  while(t--)
  {
    int n,m,i1,j1,i2,j2;
    string dir;
    cin>>n>>m>>i1>>j1>>i2>>j2>>dir;

    int bounces=0;
    bool possible = true;
    int a=i1,b=j1;

    if(check(a,b,i2,j2,dir)){
      cout<<"1\n"; continue;
    }

    placeToCorner(a,b,n,m,dir);
    int init_a = a, init_b = b;

    while(true){
      int x=a, y=b;
      placeToCorner(a,b,n,m,dir);
      change(dir);
      if(x==a && y==b){break;}
      bounces++;
      if(check(a,b,i2,j2,dir)){
        break;
      }
    }
    
  }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝