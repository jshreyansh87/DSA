// Problem Statement => https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937

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

void insertAtTail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    if(head == NULL){
        return head;
    }
    
    // Initialize 3 separate linked list to store 0s,1s,2s
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // populate the separate linked lists with 0s,1s,2s
    while(curr != NULL){
        int val = curr -> data;
        
        if(val == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1){
            insertAtTail(oneTail, curr);
        }
        else if(val == 2){
            insertAtTail(twoTail, curr);
        }
        
        curr = curr -> next;
    }
    
    // merge 3 linked lists
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }
    twoTail -> next = NULL;
    
    // update head
    head = zeroHead -> next;
    // delete dynamic memory
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}