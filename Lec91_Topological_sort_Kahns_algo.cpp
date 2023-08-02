
#include<unordered_map>
#include<list>
#include<queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Create adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
      int u = edges[i][0];
      int v = edges[i][1];

      adj[u].push_back(v);
    }

    // Find all indegrees 
    vector<int> indegree(v);     // Initialize a vector of ints of size v 
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    // Push all nodes who's indegree is 0 to the queue 
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }


    // Do BFS 
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // Store ans
        ans.push_back(front);

        // Update the indegree of neighbour to 0
        for(auto neighbour:adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    return ans; 


}