// Problem Statement => https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // base case => if list is empty or has 1 element then return this head
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    // recursive call => make a recursive call to get the head of list ahead of the current node when it is reversed
    LinkedListNode<int> *smallerList = reverseLinkedList(head -> next);
    
    // to handle 1 case => point the next of next of head back to head
    // and point next of head to null (reverse the next pointers)
    head -> next -> next = head;
    head -> next = NULL;
    
    return smallerList;
}