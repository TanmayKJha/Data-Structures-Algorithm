
class Solution {
public:
    int sum(TreeNode* root,int currSum){
        if(root==NULL){
            return 0;
        }
        currSum = currSum*10 + root->val;
        if(root->left==NULL && root->right==NULL){
           return currSum;
    }
    int left = sum(root->left, currSum);
    int right = sum(root->right, currSum);

    return (left + right);
   }
    
    int sumNumbers(TreeNode* root) {
      int totalSum = sum(root,0); 
       return totalSum;
    }
};
