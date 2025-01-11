// USING BFS KHANS ALGORITHM
class Solution {
public:
    vector<int> topologicalSort(unordered_map<int,vector<int>>&adj, int n, vector<int>&indegree){

        vector<int> result;
        queue<int> q;
        int count = 0;

        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                result.push_back(i);
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(int &a : adj[top]){
                indegree[a]--;
                if(indegree[a]==0){
                    result.push_back(a);
                    q.push(a);
                    count++;
                }
            }

        }
        if(count==n){
            return result;
        }
        return {};

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>>adj;
        vector<int> indegree(numCourses,0);

        for(vector<int> &vec :prerequisites ){
            int a = vec[0];
            int b = vec[1];

            //[a,b] means b-->a
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj,numCourses,indegree);
        
    }
};
