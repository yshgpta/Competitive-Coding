#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long arr[n];
  long dp[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++){
    dp[i]=1;
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[i]>0){
        if(arr[j]<0 && dp[j]+1>dp[i])
        dp[i]=dp[j]+1;
      }
      else{
        if(arr[j]>0 && dp[j]+1>dp[i])
        dp[i]=dp[j]+1;
      }
    }
  }
  long max = 1;
  for(int i=0;i<n;i++){
    // cout<<dp[i]<<" ";
    if(dp[i]>max)
    max=dp[i];
  }
  cout<<max;
  return 0;
}
