#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,m;
     cin>>n>>m;
     vector<int> vec[n+1];
     for(int i=0;i<m;i++){
         int u,v;
         cin>>u>>v;
         vec[u].push_back(v);
         vec[v].push_back(u);
     }

     for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(auto j: vec[i]){
           cout<<j<<" ";
        } cout<<endl;
     }

}
