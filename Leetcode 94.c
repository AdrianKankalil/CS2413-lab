/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return;

    inorder(root->left, result, index);     // Traverse left
    result[(*index)++] = root->val;         // Visit root
    inorder(root->right, result, index);    // Traverse right
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 200); // Enough for up to 100 nodes
    *returnSize = 0;
    inorder(root, result, returnSize);
    return result;
}
