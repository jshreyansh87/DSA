// Problem Statement => https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250

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

Node *findMiddle(Node *head) {
    // if list is empty or has only 1 element return head
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    // approach => take two pointers, tarverse the list with both pointers
    //             such that at each iteration fast takes two steps 
    //             and slow takes one step. So when fast reaches the end of 
    //             list at "N" nodes then slow is at "N / 2" node. 
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        
        slow = slow -> next;
    }
    
    return slow;
}