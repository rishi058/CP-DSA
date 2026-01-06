#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, val;
    Node *next, *prev;
    Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
};

class DLL{
public:
    Node *head, *tail;
    DLL(){head = tail = NULL;}

    // add a new-node in right-side and update tail.
    void push_back(Node *newNode){
        if(tail){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else{
            head = tail = newNode;
        }
    }

    void move_to_tail(Node *node){
        if(node==tail){return;}

        Node *curr_prev = node->prev;
        Node *curr_next = node->next;

        if(curr_prev){curr_prev->next = curr_next;}
        else{head=curr_next;}

        curr_next->prev = curr_prev;

        tail->next = node;
        node->prev = tail;
        node->next = NULL;
        tail = node;
    }

    void delete_head_node(){
        Node *temp = head->next;
        delete head;
        head = temp;
        if(head){temp->prev = NULL;}  // Chek if it was the only node
        else{tail=NULL;}
    }

};

class LRUCache {
public:

    int n;
    DLL list;  // LRU....MRU
    unordered_map<int,Node*> mp; // key,node 

    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key){
        // check if key doesn't exist return -1,
        if(!mp.count(key)){return -1;}
        // else move node to tail(MRU) & return its val; 
        else{
            list.move_to_tail(mp[key]);
            return list.tail->val;
        }
    }
    
    void put(int key, int value) {
        // If key already exists: Update its value & Move node to tail(MRU)
        if(mp.count(key)){
            list.move_to_tail(mp[key]);
            list.tail->val = value;
        }
        // It doesn't exist..
        // If cache is full(i.e mp.size()==n) / delete head-node(LRU) & remove its entry from mp..
        // Now add new tail-node and make its entry in mp..
        else{
            if(mp.size()==n){
                mp.erase(list.head->key);
                list.delete_head_node();
            }
            Node *newNode = new Node(key, value);
            list.push_back(newNode);
            mp[key] = newNode;
        }

    }
};

int main(){

}