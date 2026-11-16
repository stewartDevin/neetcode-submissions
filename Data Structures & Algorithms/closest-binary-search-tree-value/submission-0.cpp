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
    int closestValue(TreeNode* root, double target) {
        int val = 0;
        int closest = root->val;

        while (root != nullptr) {
            val = root->val;
            double valD = abs(val - target);
            double closestD = abs(closest - target);

            closest = 
                valD < closestD || (valD == closestD && val < closest) ? 
                val : closest;

            root = target < root->val ? root->left : root->right;
        }

        return closest;
    }
};
