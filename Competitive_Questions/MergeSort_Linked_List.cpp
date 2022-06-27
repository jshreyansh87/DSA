// Problem Statement => https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node* findMid(node* head){
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

// function to merge two sorted LL
node* merge(node* left, node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right != NULL){
        if(left -> data <= right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}

node* mergeSort(node *head) {
    // if list is empty or has only 1 element then return head
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    // find mid element
    node* middle = findMid(head);
    // divide the LL in left and right halves
    node* left = head;
    node* right = middle -> next;
    middle -> next = NULL;
    
    // recursively sort the left and right halves
    left = mergeSort(left);
    right = mergeSort(right);
    // merge the two halves and return ans
    node* result = merge(left, right);
    
    return result;
}