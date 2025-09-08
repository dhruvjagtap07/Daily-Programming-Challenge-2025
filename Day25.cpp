#include <iostream>
#include <limits.h>
using namespace std;

/*
Problem Statememt:
You are given the root of a binary tree. Your task is to determine whether the tree is a valid Binary Search Tree (BST). A binary search tree is defined as a tree where:
- Every node’s left subtree contains only nodes with values less than the node’s value.
- Every node’s right subtree contains only nodes with values greater than the node’s value.
- Both the left and right subtrees must also be binary search trees.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode *node, long minVal, long maxVal)
    {
        if (!node)
            return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

int main()
{
    // Example 1: root = [2, 1, 3] -> true
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isValidBST(root1) ? "true" : "false") << endl; // true

    // Example 2: root = [5, 1, 4, null, null, 3, 6] -> false
    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << (sol.isValidBST(root2) ? "true" : "false") << endl; // false

    // Example 3: root = [10, 5, 15, null, null, 6, 20] -> false
    TreeNode *root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(20);

    cout << (sol.isValidBST(root3) ? "true" : "false") << endl; // false

    return 0;
}