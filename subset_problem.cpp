#include<bits/stdc++.h>
using namespace std;

void PrintSubset(vector<int> &arr,vector<int> &ans,int i){
     if(i==arr.size()){
        for(auto x: ans){
            cout<<x<< " ";
        }
        cout<<endl;
        return ;
     }
     ans.push_back(arr[i]); //include
     PrintSubset(arr,ans,i+1);
     ans.pop_back(); //backtracking
     PrintSubset(arr,ans,i+1); //exclusive

}
int main(){
   vector<int> arr={1,2,3};
   vector<int> ans;
   PrintSubset(arr,ans,0);

}
