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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inOrderTraversal(root, k, count, result);
        return result;
    }

private:
    void inOrderTraversal(TreeNode* node, int k, int &count, int &result){
        if(!node) return;

        inOrderTraversal(node->left, k, count, result);

        count++;
        if(count == k){
            result = node->val;
            return;
        }

        inOrderTraversal(node->right, k, count, result);
    }
};