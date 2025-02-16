
//Using BFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> que;
        vector<vector<int>> result;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<int>level;
            while(n--){
                TreeNode* first = que.front();
                que.pop();
                level.push_back(first->val);
                if(first->left!=nullptr){que.push(first->left);}
                if(first->right!=nullptr){que.push(first->right);}
            }
            result.push_back(level);
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};
////////////////////////////////////////////////////////////-------------------------------------------------------------//////////////////////////////
//using deque
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> que;
        deque<vector<int>>result;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<int>level;
            while(n--){
                TreeNode* first = que.front();
                que.pop();
                level.push_back(first->val);
                if(first->left!=nullptr){que.push(first->left);}
                if(first->right!=nullptr){que.push(first->right);}
            }
            result.push_front(level);
        }
        
       
        return vector<vector<int>>(result.begin(),result.end());
    }
};
