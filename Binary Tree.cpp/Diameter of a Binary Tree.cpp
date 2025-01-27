class Solution {
public:
    int maxdepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftsubtree = maxdepth(root->left);
        int rightsubtree = maxdepth(root->right);
        int ans = max(leftsubtree,rightsubtree)+1;
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int option3 = maxdepth(root->left) + maxdepth(root->right);
        int ans = max({left,right,option3});
        return ans;
    }
};
