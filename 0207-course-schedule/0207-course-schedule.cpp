class Solution {
public:
    bool cycleExists(vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& pathVisited,int node)
    {
        visited[node]=true;
        pathVisited[node]=true;
        for(int i=0;i<graph[node].size();i++)
        {
            if(!visited[graph[node][i]])
            {
                if(cycleExists(graph,visited,pathVisited,graph[node][i]))
                return true;
            }
            else if(pathVisited[graph[node][i]])
            return true;
        }
        pathVisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>pathVisited(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(cycleExists(graph,visited,pathVisited,i))
                return false;
            }
        }
        return true;
    }
};