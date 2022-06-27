// Problem Statement => https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
    void insertAtTail(struct Node* &head, struct Node* &tail, int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
            return;
        }
    }
    
    struct Node* addLL(struct Node* first, struct Node* second){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        // add both LL from left to right and maintain a carry
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first -> data;
            }
            
            int val2 = 0;
            if(second != NULL){
                val2 = second -> data;
            }
            
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            if(first != NULL){
                first = first -> next;
            }
            if(second != NULL){
                second = second -> next;
            }
        }
        
        return ansHead;
    }
    
    struct Node* reverse(struct Node* head){
        if(head -> next == NULL){
            return head;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // step 1 => reverse both LL
        first = reverse(first);
        second = reverse(second);
        
        // step 2 => add both LL
        Node* ans = addLL(first, second);
        
        // step 3 => reverse ans LL
        ans = reverse(ans);
        
        return ans;
    }
};