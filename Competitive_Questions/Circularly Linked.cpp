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
    //Approach => traverse the list and check if we reach null then no circular loop
    //              if we reached the head again then circular loop present

    // empty list
    if(head == NULL){
        return false;
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
    //Approach => traverse the list and mark all the visited nodes as true
    //              if we reach at null then no circular loop
    //              if we reach an already visited node then circular loop present

    // empty list
    if(head == NULL){
        return false;
    }
    // list with 1 element
    if(head -> next == NULL){
        return false;
    }
    
    // list with more than 1 element
    unordered_map <Node*, bool> isVisited;
    
    while(head != NULL){
        if(isVisited[head] == true){
            return true;
        }
        isVisited[head] = true;
        head = head -> next; 
    }
    return false;
}


// Floyd Cycle Detection Algorithm Approach
bool isCircularApproach3(Node* head){
    //Approach => Traverse the list with two pointer fast and slow, fast moves 2 steps
    //              and slow moves 1 step at a time, if end of list reached then no circular loop
    //              if fast == slow then loop present
    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}