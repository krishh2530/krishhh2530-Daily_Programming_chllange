#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        return isValidBST(root->left, minVal, root->val) && 
               isValidBST(root->right, root->val, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    Solution solution;

    TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);
    cout << "Is Example 1 a valid BST? " << (solution.isValidBST(root1) ? "True" : "False") << endl;

    TreeNode* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);
    cout << "Is Example 2 a valid BST? " << (solution.isValidBST(root2) ? "True" : "False") << endl;

    TreeNode* root3 = newNode(10);
    root3->left = newNode(5);
    root3->right = newNode(15);
    root3->right->left = newNode(6);
    root3->right->right = newNode(20);
    cout << "Is Example 3 a valid BST? " << (solution.isValidBST(root3) ? "True" : "False") << endl;

    return 0;
}
