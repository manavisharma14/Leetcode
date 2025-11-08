class Solution {
public:
    int height(TreeNode* root, int& maxi){
        if(root == nullptr) return 0;
        int lefth = height(root->left, maxi);
        int righth = height(root->right, maxi);

        maxi = max(maxi, lefth+righth);
        return max(lefth, righth) + 1;
    }
    

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        height(root, maxi);
        return maxi;
    }
};
