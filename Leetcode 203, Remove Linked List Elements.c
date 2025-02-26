#include <stdio.h>
#include <stdlib.h>

// Function to remove elements from the linked list
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to simplify edge cases
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;  // Bypass the current node
            free(curr);  // Free memory of removed node
        } else {
            prev = curr;  // Move previous pointer forward
        }
        curr = prev->next;  // Move current pointer forward
    }
    
    head = dummy->next;  // Update the head in case the first node was removed
    free(dummy);  // Free the dummy node
    return head;
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
