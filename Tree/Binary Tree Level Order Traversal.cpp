
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                   if(temp->left!=NULL){
                      q.push(temp->left);
                     }
                    if(temp->right!=NULL){
                      q.push(temp->right);
                     }
                     v.push_back(temp->val);


            }
            ans.push_back(v);
           
        }
        return ans;
        
    }
};
