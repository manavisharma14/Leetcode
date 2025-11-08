class Solution {
public:

    int height(TreeNode* root, int &maxi){
        if(root == nullptr) return 0;

        int left = height(root->left, maxi);
        int right = height(root->right, maxi);

        // update diameter
        maxi = max(maxi, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }
};
