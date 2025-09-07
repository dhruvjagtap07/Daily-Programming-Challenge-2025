#include <iostream>
using namespace std;

/*
Problem Statement:
You are given a binary tree and two distinct nodes within the tree. Your task is to find the lowest
common ancestor (LCA) of these two nodes. The LCA of two nodes p and q is defined as the lowest node
in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself).
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }
};

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode *p = root->left;               // Node 5
    TreeNode *q = root->left->right->right; // Node 4

    TreeNode *ans = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " is: " << ans->val << endl;
    return 0;
}
