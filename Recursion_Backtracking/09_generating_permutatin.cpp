#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v, vv;
const int N = 1e5+7;
vector<bool> chosen(N,0);


void search(vector<int> permutation,vector<int> values) {  // repeated permutation is stored in case of identical elements.

    if (permutation.size() == values.size()) {
        vv.push_back(permutation);
        return;
    }
    
    for (int i = 0; i < values.size(); i++) {
        if (chosen[i]) { continue; }
        chosen[i] = true;
        permutation.push_back(values[i]);
        search(permutation, values);
        chosen[i] = false;
        permutation.pop_back();
    }
    
}


void getPerm(string &str, int index){     // recursion with swap approach more easy...
    if(index>=str.length()){
        cout<<str<<endl;
        return;
    }                                   // repeated permutation is stored in case of identical elements...

    // unordered_set<char> seen;  // To keep track of characters already used at the current index   
    //! Uncomment this if you dont want to print copies in case repetition of chars

    for(int i=index; i<str.size(); i++){
        // if (seen.find(str[i]) != seen.end()) {
        //     continue;  // Skip duplicate characters
        // }
        // seen.insert(str[i]);  // Mark character as used

        swap(str[index],str[i]);
        getPerm(str,index+1);
        swap(str[index],str[i]);        //BACK-TRACKING
    }
}

/*
1. swap 0th element with 0 to all element, them swap 1st element with 0 to all..   ..upto all elemnt ..
2. better understanding with recursion tree.
3. use -> set<string> ss to store distinct string...
*/



int main()
{
    // int n; cin>>n;
    // vector<int> permutation, empty;

    // for (int i = 0; i < n; i++){
    //     int l; cin>>l;
    //     permutation.push_back(l);
    // }

//*****************  ITERATIVE  METHOD  **********************  // best approach  -->

    // do{
    //     // process permutation
    //     v.push_back(permutation);
    // }while (next_permutation(permutation.begin(),permutation.end()));  // INBUILT FUNCTION..


//**************************************************************

    // search(empty, permutation);  // recursive method

    // for(auto s : v){
    //     cout<<"[ ";
    //     for(int c : s){
    //         cout<<c<<" ";
    //     }
    //     cout<<"]\n";
    // }

    // cout<<"\n";

    // for(auto s : vv){
    //     cout<<"[ ";
    //     for(int c : s){
    //         cout<<c<<" ";
    //     }
    //     cout<<"]\n";
    // }

    // cout<<"\nEnter a string : ";
    string j; cin>>j;
    getPerm(j,0);
}