// Problem Statement => https://leetcode.com/problems/peeking-iterator/

#include <bits/stdc++.h>
using namespace std;

class PeekingIterator : public Iterator {
public:
    int i;
    vector <int> v;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        i = 0;
        v = nums;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return v[i];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return v[i++];
	}
	
	bool hasNext() const {
	    if(i < v.size())
            return true;
        
        return false;
	}
};