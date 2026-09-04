#include<bits/stdc++.h>
using namespace std;

void Dfs(int Curr,vector<vector<int>> &graph, vector<bool> &vis,stack<int> &st){
    vis[Curr]=true;
    for(auto v: graph[Curr]){
        if(!vis[v]){
            Dfs(v,graph,vis,st);
        }
    }
   st.push(Curr);

}

void TopologicalSort(int V,vector<vector<int>> &graph){
    vector<bool> vis(V+1,false);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i])
            Dfs(i,graph,vis,st);
    }

    while(!st.empty()){
         cout<<st.top()<<" ";
         st.pop();
    }

}

int main(){
    int V=6;
    vector<vector<int>> graph(V);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);
    TopologicalSort(V,graph);
}


