#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}

const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

int search(vector<vector<int>>&v, int k, bool first){
    int lo = 0, hi = v.size()-1, idx = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        // cout<<lo<<" "<<hi<<" "<<mid<<"\n";
        // cout<<v[mid][0]<<" "<<v[mid][1]<<"\n";
        if(v[mid][0]<=k && v[mid][1]>=k){
            idx = mid;
            if(first){hi=mid-1;}
            else{lo=mid+1;}
        }

        else if(v[mid][0]>k){
            hi = mid-1;
        }
        else if(v[mid][1]<k){
            lo = mid+1;
        }
        // cout<<lo<<" "<<hi<<" "<<mid<<"\n";

    }

    return idx;
}

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    int m = flowers.size(), n = people.size();
    sort(flowers.begin(), flowers.end());
    
    for(int i=0; i<m; i++){
        cout<<flowers[i][0]<<" "<<flowers[i][1]<<"\n";
    }

    vector<int> ans;
    for(int i=0; i<n; i++){
        int t = people[i];
        int left = search(flowers, t, 1);
        int right = search(flowers, t, 0);
        if(left==-1){ans.push_back(0);}
        else{ans.push_back(right-left+1);}
    }

    return ans;
}

int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        vector<vi> tmp =  {{21,34},{17,37},{23,43},{17,46},{37,41},{44,45},{32,45}};
        vi v = {31,41,10,12};
        vi ans=fullBloomFlowers(tmp, v);
        print(ans);
        
    }

}



//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝