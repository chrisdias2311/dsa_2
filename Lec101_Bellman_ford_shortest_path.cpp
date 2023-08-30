#include<iostream>
using namespace std;
#include<vector>

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    //n-1 times 
    for(int i=1; i<=n; i++){       
        //Traverse all edge list 
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + wt)<dist[v])){       //First check if existing distance till node is not infinity 
                dist[v] = dist[u] + wt;
            }
        }
    }



    //Check for negetive cycle    (run the loop one last time to check if the distance updates)
    bool flag = 0;
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + wt)<dist[v])){   //If distance updates then make the flag as 1;
            flag = 1;
        }
    }

    if(flag == 0)
        return dist[dest];
    return -1;

}