#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tuple array<int, 3>
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

//https://leetcode.com/problems/lfu-cache/

struct Node {
  int key;
  int value;
  int freq;
  list<int>::const_iterator it;
};

class LFUCache {
 public:
  LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

  int get(int key) {
    if (!keyToNode.count(key))
      return -1;

    Node& node = keyToNode[key];
    touch(node);
    return node.value;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    if (keyToNode.count(key)) {
      Node& node = keyToNode[key];
      node.value = value;
      touch(node);
      return;
    }

    if (keyToNode.size() == capacity) {
      // Evict LRU key from the minFreq list
      const int keyToEvict = freqToList[minFreq].back();
      freqToList[minFreq].pop_back();
      keyToNode.erase(keyToEvict);
    }

    minFreq = 1;
    freqToList[1].push_front(key);
    keyToNode[key] = {key, value, 1, cbegin(freqToList[1])};
  }

 private:
  int capacity;
  int minFreq;
  unordered_map<int, Node> keyToNode;
  unordered_map<int, list<int>> freqToList;

  void touch(Node& node) {
    // Update the node's frequency
    const int prevFreq = node.freq;
    const int newFreq = ++node.freq;

    // Remove the iterator from prevFreq's list
    freqToList[prevFreq].erase(node.it);
    if (freqToList[prevFreq].empty()) {
      freqToList.erase(prevFreq);
      // Update minFreq if needed
      if (prevFreq == minFreq)
        ++minFreq;
    }

    // Insert the key to the front of newFreq's list
    freqToList[newFreq].push_front(node.key);
    node.it = cbegin(freqToList[newFreq]);
  }
};

int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        
    }

}


//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝