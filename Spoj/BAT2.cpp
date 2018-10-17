#include <bits/stdc++.h>
using namespace std;
long long arr[103],n;
long long dp[103][103][103];

long long solve(int i,int in,int dec){
  if(i>n+1)
  return 0;
  if(dp[i][in][dec]!=-1)
  return dp[i][in][dec];
  dp[i][in][dec]=solve(i+1,in,dec);
  if(arr[i]>arr[in])
  dp[i][in][dec]=max(dp[i][in][dec],solve(i+1,i,dec)+1);
  if(arr[i]<arr[dec])
  dp[i][in][dec]=max(dp[i][in][dec],solve(i+1,in,i)+1);
  return dp[i][in][dec];
}
int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=2;i<=n+1;i++)
    cin>>arr[i];
    arr[0]=-LLONG_MAX;
    arr[1]=LLONG_MAX;
    memset(dp,-1,sizeof(dp));
    cout<<solve(2,0,1)<<endl;
  }
  return 0;
}
