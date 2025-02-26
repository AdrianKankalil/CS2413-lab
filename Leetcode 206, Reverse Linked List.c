#include <stdio.h>
#include <stdlib.h>

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;  // Pointer to track previous node
    struct ListNode* curr = head;  // Pointer to traverse the list
    
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next; // Store next node
        curr->next = prev;  // Reverse the link
        prev = curr;  // Move prev forward
        curr = nextTemp;  // Move curr forward
    }
    
    return prev;  // New head of the reversed list
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}
