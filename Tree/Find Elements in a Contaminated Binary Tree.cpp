//T.C--> O(N)-->DFS traversal +O(1)-->finding target element;
//SC-->O(N)-->unorderedSet
class FindElements {
public:
    unordered_set<int>st;
    void DFS(TreeNode* root){
        if(root==NULL){
            return ;
        }
        st.insert(root->val);
        if(root->left!=NULL){
            root->left->val = 2*root->val+1;
        }
        if(root->right!=NULL){
            root->right->val= 2*root->val +2;
        }
        DFS(root->left);
        DFS(root->right);
    }
    
    FindElements(TreeNode* root) {
        st.clear();
        if(root!=NULL){
           root->val = 0;
           DFS(root);
        }
    }
    
    bool find(int target) {
        
       if(st.find(target)!=st.end()){
        return true;
       }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
