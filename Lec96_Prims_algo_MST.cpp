#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>

// https://www.codingninjas.com/studio/problems/prim-s-mst_1095633?leftPanelTab=1

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    //N = Number of nodes in the graph 
    //M = number of edges in the graph

    // Create Adj list 
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;                         // ((1, 2),3) edge between 1 and 2 with weight 3
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }



    // Lets start the Algo 
    key[1] = 0;
    parent[1] = -1;

    for(int i=0; i<n; i++){
        int mini = INT_MAX;
        int u;
        //Find the min node
        for(int v=1; v<=n; v++){
            if(mst[v]==false && key[v]<mini){
                u=v;              //u = node
                mini=key[v];      //mini = weight 
            }
        }

        //Mark the min node as True
        mst[u] = true;

        //Check its adjacent nodes
        for(auto it:adj[u]){
            int v = it.first;    //value
            int w = it.second;   //weight

            if(mst[v]==false && w<key[v]){
                parent[v] = u;
                key[v] = w;
            }

        }
    }


    //Prepare answer (Parent, mst, key) are now ready 
    vector<pair<pair<int, int>, int>>result;
    for(int i=2; i<=n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
