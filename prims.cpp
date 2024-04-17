
#include <bits/stdc++.h>
#define N 8
using namespace std;
void addEdge(unordered_map<int, list<pair<int, int>>>& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(v,weight));
}


int main(){

    int n = 5;
    unordered_map<int, list<pair<int, int>>> adj;    
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 2, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 2, 3, 50);
    addEdge(adj, 3, 4, 60);
    
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);
    vector<int> key(n,INT_MAX);
    
    key[0] = 0;
    
    for(int i = 0;i<n;i++){
        int u;
        int mini = INT_MAX;
        
        for(int v = 0;v < n;v++){
            if(mst[v] == false && key[v] < mini){
                mini = key[v];
                u = v;
            }
        }
        mst[u] = true;
        
        for(auto x : adj[u]){
            int node = x.first;
            int weight = x.second;
            
            if(mst[node] == false && key[node] > weight){
                key[node] = weight;
                parent[node] = u;
            }
        }
        
    }
    for(int i = 0;i<parent.size();i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    
    

	return 0;
}

