#include<bits/stdc++.h>
using namespace std;

long long exponen(int  base,int power){
      int res=1;
      while(power>0){
         if(power&1) res=res*base;
         base*=base;
         power=power>>1;
      }
   return res;

}

int main(){
     int base,power;
     cin>>base>>power;
     cout<<exponen(base,power)<<endl;

}
