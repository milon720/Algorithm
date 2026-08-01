#include<bits/stdc++.h>
using namespace std;

class NewArray{
    public:
       vector<int> arr,block;
       int n,blocksize;

       NewArray(vector<int> &arr){
        this->arr=arr;
        n=arr.size();

        //build the block
        blocksize=ceil(sqrt(n));
        block.resize(blocksize,0);
        for(int i=0;i<n;i++){
            block[i/blocksize]+=arr[i];
        }
       }

       void update(int index,int val){
           block[index/blocksize]+=(val-arr[index]);
           arr[index]=val;
       }

       int query(int l,int r){
           int sum=0;
           //case 1;
           int startB=l/blocksize;
           int endB=r/blocksize;
           if(startB==endB){
              for(int i=l;i<=r;i++){
                sum+=arr[i];
              }
              return sum;
           }
           //case 2;
           int endOFindexstartB=((startB+1)*blocksize)-1;
           for(int i=l;i<=endOFindexstartB;i++){
              sum+=arr[i];
           }
           for(int i=startB+1;i<endB;i++){
             sum+=block[i];
           }
           int stratindexOfendB=endB*blocksize;
           for(int i=stratindexOfendB;i<=r;i++){
              sum+=arr[i];
           }
           return sum;

       }

};

int main(){
     vector<int> arr={1,2,3,4,5,6,7,8,9};
     NewArray obj(arr);
     cout<<obj.query(2,7)<<endl;
     obj.update(3,10);
     cout<<obj.query(2,7)<<endl;
}
