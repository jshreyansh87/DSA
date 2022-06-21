// Problem Statement => https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};



Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL){
        return NULL;
    }
    
    // solving 1 case
    // reverse the first k nodes using iterative method
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    
    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        
        count++;
    }
    
    // recursive call
    // if next exist then call the function recursivly for next node
    if(next != NULL){
        head -> next = kReverse(next, k);
    }
    
    return prev;
}