// Problem Statement => https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232
// The test cases for the above problem are wrong on coding ninjas

#include <bits/stdc++.h>
using namespace std;

     
class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
};

bool isCircularApproach1(Node* head){
    // empty list
    if(head == NULL){
        return true;
    }
    // list with 1 element
    if(head -> next == NULL){
        return false;
    }
    
    // list with more than 1 element
    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
    
    if(temp == NULL){
        return false;
    }
    return true;
}

bool isCircularApproach2(Node* head){
    // empty list
    if(head == NULL){
        return true;
    }
    // list with 1 element
    if(head -> next == NULL){
        return false;
    }
    
    // list with more than 1 element
    unordered_map <Node*, bool> isVisited;
    
    while(head != NULL && isVisited[head] == false){
        isVisited[head] = true;
        head = head -> next; 
    }
    
    if(head == NULL){
        return false;
    }
    
    return true;
}