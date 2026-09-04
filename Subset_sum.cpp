#include<bits/stdc++.h>
using namespace std;

bool findSum(vector<int> &arr,int n,int sum){
      //when sum=0
      if(sum==0) return true;

      //if Cover all element
      if(n==0) return false;

      //when current element bigger than sum
      if(arr[n-1]>sum){
         findSum(arr,n-1,sum);
      }
      //two choice 1.exclude 2.include
      return findSum(arr,n-1,sum)|| findSum(arr,n-1,sum-arr[n-1]);

}

int main(){
    vector<int> arr={3,4,5};
    int target=9;
    if(findSum(arr,arr.size(),target)){
        cout<<"The Array Exist The Sum";
    }
    else cout<<"The Array Dose Not Exist The Sum";



}
