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

bool isPal(string s){
    int a = 0, b = s.size()-1;
    while(a<b){
        if(s[a]!=s[b]){return false;}
        a++; b--;
    }
    return true;
}

vector<vector<string>> allPartitions;
int n;

void solve(int ind, string &str, vector<string> &curr){
    if(ind==n){
        allPartitions.push_back(curr);
        return;
    }

    string temp;
    for(int i=ind; i<n; i++){
        temp.push_back(str[i]);
        curr.push_back(temp);
        solve(i+1, str, curr);
        curr.pop_back();
    }

}

vector<vector<string>> partition(string str) {
    n = str.size();
    vector<string> v;
    solve(0, str, v);

    vector<vector<string>> ans;
    for(auto vec : allPartitions){
        bool ok = true;
        for(string s : vec){
            ok &= isPal(s);
        }
        if(ok){
            ans.push_back(vec);
        }
    }

    return ans;
}


int32_t main()
{
    RISHI
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for(auto it : ans){
        cout<<"[ ";
        for(auto x : it){
            cout<<x<<", ";
        }
        cout<<"]\n";
    }
}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝