class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root; // Base case: the tree is empty or the key is not found
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Search in the left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Search in the right subtree
        } else {
            // Found the node to delete
            if (root->left == nullptr) {
                return root->right; // If the left child is null, return the right child
            } else if (root->right == nullptr) {
                return root->left; // If the right child is null, return the left child
            }

            // Node has two children: Replace with the inorder successor (min value in the right subtree)
            TreeNode* successor = findMin(root->right);
            root->val = successor->val; // Replace the value
            root->right = deleteNode(root->right, successor->val); // Delete the successor node
        }

        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left; // Go to the leftmost node
        }
        return node;
    }
};
