// Problem Statement => https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283

#include <bits/stdc++.h>
using namespace std;


    
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node * uniqueSortedList(Node * head) {
    if(head ==NULL){
        return head;
    }
    
    Node* curr = head;
    
    while(curr != NULL){
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data){
            Node* next_next = curr -> next -> next;
            delete(curr -> next);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }
    }
    
    return head;
}