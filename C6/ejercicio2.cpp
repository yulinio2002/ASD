class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr); 
    }

    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {

        if (!node) return true;

        if ((minNode && node->val <= minNode->val) || (maxNode && node->val >= maxNode->val)) {
            return false; 
        }

        return validate(node->left, minNode, node) && validate(node->right, node, maxNode);
    }
};