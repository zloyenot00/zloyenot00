#include "mylib.h"
TreeNode* createTreeNode(float data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
TreeNode* insertTree(TreeNode* root, float data) {
    if (!root) return createTreeNode(data);
    if (data < root->data)
        root->left = insertTree(root->left, data);
    else if (data > root->data)
        root->right = insertTree(root->right, data);

    return root;
}
float findMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root->data;
}

float findMax(TreeNode* root) {
    while (root->right)
        root = root->right;
    return root->data;
}
void freeTree(TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
