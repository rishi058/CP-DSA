#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*

Normal Set ->
insert unique elements in O(1) or O(logn)
s.find / st.lower_bound / st.upper_bound in O(logn)
st.erase in O(1) or O(logn)

Ordred_Set ->
  Special Functionalities [O(logn)] ==>

- order_of_key(k) : Number of items strictly less than K.   // Can be also implemeted using some techniques in normal set in O(logn)
- find_by_order(k) : Kth element in a set(counting from 0).  // Random access [Unique]

*/

int main(){
    oset<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    for(int x : st){cout<<x<<" ";}
}