/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    result[(*index)++] = root->val;         // Visit root
    preorder(root->left, result, index);    // Traverse left
    preorder(root->right, result, index);   // Traverse right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 200); // Enough for 0 <= nodes <= 100
    *returnSize = 0;
    preorder(root, result, returnSize);
    return result;
}
