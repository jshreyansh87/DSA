// Problem Statement => https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331

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

Node *removeDuplicates(Node *head)
{
    if(head == NULL){
        return head;
    }
    
    unordered_map <int, bool> isPresent;
    
    Node* prev = head;
    Node* curr = head -> next;
    
    isPresent[prev -> data] = true;
    
    while(curr != NULL){
        if(isPresent[curr -> data] == true){
            prev -> next = curr -> next;
            free(curr);
        }
        else{
            isPresent[curr -> data] = true;
            prev = curr;
        }
        curr = prev -> next;
    }
    
    return head;
}