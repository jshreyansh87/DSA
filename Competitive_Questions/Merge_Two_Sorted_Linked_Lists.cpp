// Problem Statement => https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

Node<int>* mergeLL(Node<int>* first, Node<int>* second){
    // if only one element in first LL then attach second LL in first and return first
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }
    
    // Approach => keep two pointers in 1st LL at 1st and 2nd nodes and check
    //             if current element of 2nd LL is to be placed between the above 
    //             two pointers then update the pointers and move curr1 to newly added
    //             node. Else update both pointer in 1st LL.
    
    // create pointers to keep track of LL
    Node<int>* curr1 = first;
    Node<int>* next1 = first -> next;
    Node<int>* curr2 = second;
    
    // traverse the LL and merge
    while(next1 != NULL && curr2 != NULL){
        // if element in curr2 can be placed b/w curr1 and next1
        if((curr1 -> data <= curr2 -> data) && (curr2 -> data <= next1 -> data)){
            // then add curr2 after curr1
            // add next1 after curr2
            // and update the required pointers
            curr1 -> next = curr2;
            curr2 = curr2 -> next;
            curr1 -> next -> next = next1;
            
            curr1 = curr1 -> next;
        }
        else{
            // increment both pointers of 1st LL
            curr1 = curr1 -> next;
            next1 = next1 -> next;
            // if next1 is null
            if(next1 == NULL){
                // then append the left out nodes in 2nd LL to the 1st LL and return 1st LL
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // if any LL is empty then return the other one
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    
    // call the mergeLL function such that the data at 1st node is smaller in 1st argument
    if(first -> data <= second -> data){
        return mergeLL(first ,second);
    }
    else{
        return mergeLL(second ,first);
    }
}