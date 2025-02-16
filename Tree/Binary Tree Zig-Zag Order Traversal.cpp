
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);
        vector<vector<int>>result;
        int level = 0 ;
        while(!que.empty()){
            int n = que.size();
            vector<int>temp;
            while(n--){
                TreeNode* first = que.front();
                que.pop();
                temp.push_back(first->val);
                if(first->left!=nullptr){que.push(first->left);}
                if(first->right!=nullptr){que.push(first->right);}
            }        
            if(level%2!=0){
              reverse(temp.begin(),temp.end());
            }
            result.push_back(temp);
            level++;
        }
        
        return result;
    }
};
