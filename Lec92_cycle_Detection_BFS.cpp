#include<unordered_map>
#include<list>
#include<queue>

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // Create adj list
  unordered_map<int, list<int>> adj;

  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first-1;
    int v = edges[i].second-1;

    adj[u].push_back(v);
  }

  // Find all indegrees
  vector<int> indegree(n); // Initialize a vector of ints of size v
  for (auto i : adj) {
    for (auto j : i.second) {
      indegree[j]++;
    }
  }

  // Push all nodes who's indegree is 0 to the queue
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  // Do BFS
  int cnt = 0;
  while (!q.empty()) {
    int front = q.front();
    q.pop();

    // Store ans
    cnt++;

    // Update the indegree of neighbour to 0
    for (auto neighbour : adj[front]) {
      indegree[neighbour]--;
      if (indegree[neighbour] == 0) {
        q.push(neighbour);
      }
    }
  }

  if(cnt==n)
      return false;     // If counted number of nodes is equals to the actual number of nodes, cycle is not presend 
  else 
      return true;      // else retuen cycle is present 
}