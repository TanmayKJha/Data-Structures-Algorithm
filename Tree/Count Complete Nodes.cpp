//USING logN time complexity
class Solution {
public:
    int getLeftheight(TreeNode* root){
        TreeNode* temp = root;
        int leftht = 0;
        while(temp!=NULL){
            temp = temp->left;
            leftht++;
        }
        return leftht;
    }

     int getRightheight(TreeNode* root){
        TreeNode* temp = root;
        int  rightht = 0;
        while(temp!=NULL){
            temp = temp->right;
            rightht++;
        }
        return rightht;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL){
           return 0;
        }
        int lh = getLeftheight(root);
        int rh = getRightheight(root);
        
        if(lh ==rh){
            return (pow(2,lh)-1);
        }
        return countNodes(root->left) + countNodes(root->right) +1;  //Adding root node
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////


//Using O(N) time Complexity--Any DFS

class Solution {
public:
    int dfs(TreeNode* root){
        if(root ==NULL){
            return 0 ;
        }
        int count = 1;
        if(root->left!=NULL){
            count+=dfs(root->left);
        }
        if(root->right!=NULL){
            count+=dfs(root->right);
        }
         return count;
        
    }
    int countNodes(TreeNode* root) {
        int totalCount = dfs(root);
        return totalCount;
    }
};
