#include<algorithm>

bool cmp(vector<int> &a, vector<int> &b){
  // Since weight is at the third index we compare a[2] and a[3]
  return a[2]<b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0; i<n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}



int findParent(vector<int>&parent, int node){
  if(parent[node]==node){    // Reached the final prent in the hirerchy 
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);    // Path compression 
}



void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u]<rank[v]){
    parent[u] = v;
  }else if(rank[v]<rank[u]){
    parent[v] = u;
  }else{
    parent[v] = u;
    rank[u]++;
  }
}



int minimumSpanningTree(vector<vector<int>>& edges, int n){

  // IN Kruskals algorithm we do not make an adjecency list, instead we make a linear DS     [wt, u, v]

  //The sort function is like a magic wand that arranges the lists in a particular order. It needs this cmp helper to understand how to compare the lists correctly.
  // So, the sort function takes a list of lists (vector of vectors) called "edges". It sorts these lists based on their weights (the third number in each list) using the cmp helper.
  sort(edges.begin(), edges.end(), cmp);      // Time complexity for sorting m edges = mlogm


  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minWeight = 0;

  for(int i=0; i<edges.size(); i++){
    int u=findParent(parent, edges[i][0]);
    int v=findParent(parent, edges[i][1]);
    int wt=edges[i][2];

    if(u!=v){      // Both the parents belong to different components & hence we have to do union
      minWeight += wt;
      unionSet(u, v, parent, rank);
    }
  }
  return minWeight;
}