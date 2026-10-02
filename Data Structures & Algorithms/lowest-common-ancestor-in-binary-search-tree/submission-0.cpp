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
    TreeNode* lookFor(TreeNode* root, TreeNode* node) {
            if (!root || root->val == node->val)
                return root;
            else if(root->val > node->val)
                return lookFor(root->left, node);
            return lookFor(root->right, node);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        
        if (lookFor(root->left, p) && !lookFor(root->left, q))
            return root;

        else if (lookFor(root->left, q) && !lookFor(root->left, p))
            return root;
        
        else if (lookFor(root->left, p) && lookFor(root->left, q))
            return lowestCommonAncestor(root->left, p, q);

        return lowestCommonAncestor(root->right, p, q);
    }
};
