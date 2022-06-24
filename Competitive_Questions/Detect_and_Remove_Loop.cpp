// Problem Statement => https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049

#include <bits/stdc++.h>
using namespace std;

    
class Node {
    public :
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

// Floyd Cycle Detection Algorithm Approach
Node* getIntersection(Node* head){
    //Approach => Traverse the list with two pointer fast and slow, fast moves 2 steps
    //              and slow moves 1 step at a time, if end of list reached then no circular loop
    //              if fast == slow then loop present

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        
        if(fast == slow){
            return slow;
        }
    }

    return NULL;
}

Node* getStartNodeOfLoop(Node* head, Node* intersection){
    // Approach => move the head and intersection(where fast and slow pointer met in floyd cycle detection)
    //                by 1 and the node where they meet now will be the starting node of loop
    while(head != intersection){
        head = head -> next;
        intersection = intersection -> next;
    }
    
    return head;
}

Node *removeLoop(Node *head)
{
    if(head == NULL){
        return head;
    }
    
    Node* intersection = getIntersection(head);
    if(intersection == NULL){
        return head;
    }
    
    Node* startNodeOfLoop = getStartNodeOfLoop(head, intersection);
    
    // Tarverse the list from starting of loop and check if the next node is again starting node
    // then point the next pointer to null
    Node* temp = startNodeOfLoop;
    while(temp -> next != startNodeOfLoop){
        temp = temp -> next;
    }
    
    temp -> next = NULL;
    return head;
}