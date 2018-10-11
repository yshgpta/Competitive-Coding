#include<bits/stdc++.h>
using namespace std;
long long int m=100000000;
long long dp[4001];
void initialize(){
  for(int i=0;i<=4001;i++)
  dp[i]=-1;
}
long long fun(int n,int a,int b,int c){
  if(n==0)
  return 0;
  if(n<0)
  return -m;
  if(dp[n]!=-1)
  return dp[n];
  else
  return dp[n]=max(1+fun(n-a,a,b,c),max(1+fun(n-b,a,b,c),1+fun(n-c,a,b,c)));
}

int main(){
  initialize();
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  cout<<fun(n,a,b,c);
  return 0;
}
