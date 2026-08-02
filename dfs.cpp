#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
vector<bool> vis(100);

void dfs(int u){
      vis[u]=true;
      cout<<u<<" ";
      for(int v : graph[u]){
         if(!vis[v]) dfs(v);
      }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u); //if bidirectional graph
    }
    //if disconnect graph
    for(int i=1;i<=n;i++){
        if(!vis[i])
            dfs(i);   //start form 0
    }

}
