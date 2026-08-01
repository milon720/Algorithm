#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> & v,int val){
      int low=0;
      int high=v.size()-1;
      while(low<=high){
          int mid=(low+high)/2;
          if(v[mid]==val){
            return mid;
          }
          else if(v[mid]val){
             low=mid+1;
          }
          else{
             high=mid-1;
          }
      }
      return -1;

}

int main(){
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0;i<n;i++) cin>>v[i];
      sort(v.begin(),v.end());
      int val;
      cout<<"Which value U want to be search"<<endl;
      cin>>val;
      int result=binarySearch(v,val);
      cout<<result<<endl;


}



