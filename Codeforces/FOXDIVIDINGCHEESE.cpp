#include<bits/stdc++.h>
using namespace std;
int main(){
  long a,b;
  cin>>a>>b;
  if(a==b){
    cout<<"0";
    return 0;
  }
  vector<long> v1(4,0),v2(4,0);
  while(a%2==0 || a%3==0 || a%5==0){
    if(a%2==0){
      v1[1]++;
      a/=2;
    }
    if(a%3==0){
      v1[2]++;
      a/=3;
    }
    if(a%5==0){
      v1[3]++;
      a/=5;
    }
  }
  v1[0]=a;
  while(b%2==0 || b%3==0 || b%5==0){
    if(b%2==0){
      v2[1]++;
      b/=2;
    }
    if(b%3==0){
      v2[2]++;
      b/=3;
    }
    if(b%5==0){
      v2[3]++;
      b/=5;
    }
  }
  v2[0]=b;
  if(v1[0]!=v2[0]){
    cout<<"-1";
  }else{
    cout<<abs(v1[1]-v2[1])+abs(v1[2]-v2[2])+abs(v1[3]-v2[3]);
  }
  return 0;
}
