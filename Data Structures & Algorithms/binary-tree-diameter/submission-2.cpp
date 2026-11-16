/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        dfs(root, d);
        return d;
    }

private:
    int dfs(TreeNode* node, int& d) {
        if (node == nullptr) return 0;

        int left = dfs(node->left, d);
        int right = dfs(node->right, d);
        
        d = max(d, left + right);

        return max(left, right) + 1;
    }
};
