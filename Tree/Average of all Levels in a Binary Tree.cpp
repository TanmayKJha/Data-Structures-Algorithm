
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        vector<double> avg;
       
        while(!que.empty()){
            int n = que.size();
            double count = 0;
            double sum = 0;
            while(n--){
                TreeNode* first = que.front();
                que.pop();
                sum+=first->val;
                count++;
                if(first->left!=NULL){que.push(first->left);}
                if(first->right!=NULL){que.push(first->right);}
                
            }
            avg.push_back(sum/count);
        }
        return avg;       
    }
};
