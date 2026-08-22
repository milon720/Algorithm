#include<bits/stdc++.h>
using namespace std;
vector<bool> vis(1000,false);//for dfs
vector<bool> vis1(1000,false); //for bfs

void dfs(int u,vector<vector<int>> &vec){
   vis[u]=true;
   cout<<u<<" ";
   for(auto v: vec[u]){
     if(!vis[v]){
         dfs(v,vec);
     }
   }
}

void bfs(int start,vector<vector<int>> &vec){
    queue<int> q;
    q.push(start);
    vis1[start]=true;
    while(q.size()>0){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(auto v: vec[u]){
            if(!vis1[v]){
                vis1[v]=true;
                q.push(v);
            }
        }
    }

}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>> vec(n+1);
   for(int i=01;i<m+1;i++){
     int u,v;
     cin>>u>>v;
     vec[u].push_back(v);
     vec[v].push_back(u);
   }
   cout<<"DFS"<< " ";
   dfs(1,vec);
   cout<<endl;
   cout<<"BFS"<<" ";
   bfs(1,vec);

}
