#include<bits/stdc++.h>
using namespace std;

map<int,long long> dp;

long long res(long long n){
  if(n==0)
  return 0;
  if(dp[n]!=0)
  return dp[n];
  else{
    long long val = res(n/2)+res(n/3)+res(n/4);
    if(val>n)
    return dp[n] = val;
    else
    return dp[n] = n;
  }
}

int main(){
  for(int i=1;i<=4;i++)
  dp[i]=i;
  long long n;
  while(cin>>n){
    cout<<res(n)<<endl;
  }
  return 0;
}
