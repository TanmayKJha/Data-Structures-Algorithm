//Doubt why indegree-- in line23
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        int count = 0;
   
        
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }
        
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]) {
                
                indegree[v]--;
                
                if(indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
                
            }
            
        }
        
        return (count==n) ? true:false;
            
    }
    bool canFinish(int numsCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numsCourses,0);
        for(vector<int> &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSortCheck(adj,numsCourses,indegree);
        
    }
};
