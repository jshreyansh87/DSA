// Problem Statement  =>   https://leetcode.com/problems/design-hashset/


#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    vector <bool> v;
    MyHashSet() {
        v.resize(1e6 + 1, false);
    }
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;
    }
    
    bool contains(int key) {
        return v[key];
    }
};