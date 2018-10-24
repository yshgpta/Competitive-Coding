#include<bits/stdc++.h>
using namespace std;
int arr[101];
void initialize(){
  for(int i=0;i<101;i++)
  arr[i]=1;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    initialize();
    int m,x,y;
    cin>>m>>x>>y;
    int dis = x*y;
    while(m--){
      int a,upper,lower;
      cin>>a;
      if(a+dis>100)
      upper=100;
      else
      upper=a+dis;
      if(a-dis<1)
      lower=1;
      else
      lower=a-dis;
      for(int i=lower;i<=upper;i++)
      arr[i]=0;
    }
    int count=0;
    for(int i=1;i<101;i++){
      if(arr[i])
      count++;
    }
    cout<<count<<endl;
  }
  return 0;
}
