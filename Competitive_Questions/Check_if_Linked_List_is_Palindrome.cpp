// Problem Statement => https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/#

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  private:
    Node* reverseLL(Node* head){
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    Node* findMiddle(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next;
            if(fast -> next != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
        }
        
        return slow;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // if only 1 element
        if(head == NULL || head -> next == NULL){
            return true;
        }
        
        // find middle of LL
        Node* middle = findMiddle(head);
        
        // reverse the LL ahead of middle
        Node* temp = middle -> next;
        middle -> next = reverseLL(temp);
        
        // compare element from head and middle next
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                // retrieve the original LL by reversing the LL ahead of middle again (Below 2 lines are optional)
                temp = middle -> next;
                middle -> next = reverseLL(temp);
                return false;
            }
            
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        // retrieve the original LL by reversing the LL ahead of middle again (Below 2 lines are optional)
        temp = middle -> next;
        middle -> next = reverseLL(temp);
        
        return true;
    }
};