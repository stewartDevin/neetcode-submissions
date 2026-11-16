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
        int closest = root->val;

        while (root != nullptr) {
            double currDiff = abs(root->val - target);
            double closestDiff = abs(closest - target);

            if (currDiff < closestDiff || (currDiff == closestDiff && root->val < closest)) {
                closest = root->val;
            }

            if (currDiff == 0.0) {
                return closest;
            }

            root = (target < root->val) ? root->left : root->right;
        }

        return closest;
    }
};
