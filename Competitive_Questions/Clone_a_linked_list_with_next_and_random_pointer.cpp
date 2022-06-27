// Problem Statement => https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

// < ---------- Approach 1 ---------- >
class SolutionApproach1
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        // step 1 => clone original list using only next pointer
        Node* originalNode = head;
        while(originalNode != NULL){
            insertAtTail(cloneHead, cloneTail, originalNode -> data);
            originalNode = originalNode -> next;
        }
        
        // step 2 => map the originalNode with its cloneNode
        unordered_map <Node*, Node*> oldToCloneMapping;
        originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL){
            oldToCloneMapping[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        // step 3 => find the random pointer node for each node in original list and find its corresponding cloneNode using map
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode -> arb = oldToCloneMapping[originalNode -> arb];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
    }

};


// < ---------- Approach 2 ---------- >
class SolutionApproach2
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        // step 1 => clone original list using only next pointer
        Node* originalNode = head;
        while(originalNode != NULL){
            insertAtTail(cloneHead, cloneTail, originalNode -> data);
            originalNode = originalNode -> next;
        }
        
        // step 2 => add cloneNodes between originalNodes
        originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        // step 3 => copy random pointer
        Node* temp = head;
        while(temp != NULL){
            if(temp -> next != NULL){
                if(temp -> arb != NULL){
                    temp -> next -> arb = temp -> arb -> next;
                }
                // else{
                //     temp -> next -> arb = NULL;
                // }
            }
            
            temp = temp -> next -> next;
        }
        
        // step 4 => revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }

        // step 5 => return ans
        return cloneHead;
    }
};