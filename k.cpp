#include<bits/stdc++.h>
using namespace std;

class DSU{
     vector<int> parent, rankv;

public:
   DSU(int n){
     for(int i=0;i<n;i++){
         parent.push_back(i);
         rankv.push_back(0);
     }
   }

   int find(int x){
      if(parent[x]==x) return x;
      return parent[x]=find(parent[x]);
   }

   bool unite(int a,int b){
       a=find(a);
       b=find(b);

       if(a==b) return false;

       if(rankv[a]==rankv[b]){
          parent[b]=a;
          rankv[a]++;
       }
       else if(rankv[a]>rankv[b])
          parent[b]=a;
       else
          parent[a]=b;

       return true;
   }
};


struct Edge{
    int u,v,w;
};

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}


int main(){

    int n,m;
    cin>>n>>m;

    vector<Edge> edge;

    for(int i=0;i<m;i++){
        Edge e;
        cin>>e.u>>e.v>>e.w;
        edge.push_back(e);
    }

    sort(edge.begin(),edge.end(),cmp);

    DSU dsu(n);

    int cost=0;

    for(auto e:edge){
        if(dsu.unite(e.u,e.v)){
            cost+=e.w;
        }
    }

    cout<<"MST Cost = "<<cost<<endl;

    return 0;
}