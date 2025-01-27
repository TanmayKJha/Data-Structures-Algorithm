
class Solution {
public:

    bool solve(TreeNode*L, TreeNode* R){

        if(L==NULL && R==NULL){
            return true;
        }

        if(L==NULL || R==NULL){
            return false;
        }
        
        if(L->val!=R->val){
            return false;
        }

        return solve(L->left,R->right) && solve(L->right,R->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        return solve(root->left,root->right);
    }
};
