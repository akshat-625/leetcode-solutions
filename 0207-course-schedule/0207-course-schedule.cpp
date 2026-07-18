class Solution {
public:


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> inDegree(numCourses, 0);  // Stores in-degree of each node
        queue<int> q;                // Queue for processing nodes

        vector<vector<int>>adj(numCourses);
        for(auto &vec:prerequisites){
            adj[vec[0]].push_back(vec[1]);
        }

        // Compute in-degree of each node
        for(int i=0;i<numCourses;i++){
            for(auto &nbr:adj[i]){
                inDegree[nbr]++;
            }
        }
        // Push all nodes with in-degree 0 into the queue
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

    int processedNodes = 0;  // Count nodes processed

    // Process nodes using BFS

    while(!q.empty()){
        int node=q.front();
        q.pop();
        processedNodes++;
        for(auto &nbr:adj[node]){
            inDegree[nbr]--;
            if(inDegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    cout<<processedNodes<<" "<<numCourses<<"\n";
    // if eqaul mean no cycle
    return processedNodes==numCourses;
    }
};