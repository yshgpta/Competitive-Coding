#include<bits/stdc++.h>
using namespace std;
int main(){
  long n;
  cin>>n;
  long long arr[n+1],dp[n+1];
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    dp[i]=1;
  }
  int flag;  //0 for negative 1 for positive
  if(arr[2]-arr[1]<0)
  flag=0;
  else
  flag=1;
  dp[2]=2;
  for(int i=3;i<=n;i++){
    if(flag==0){
      if(arr[i]-arr[i-1]>0){
        dp[i]=dp[i-1]+1;
        flag=1;
      }
      else
      dp[i]=dp[i-1];
    }else{
      if(flag==1 && arr[i]-arr[i-1]<0){
        dp[i]=dp[i-1]+1;
        flag=0;
      }
      else
      dp[i]=dp[i-1];
    }
  }
  // for(int i=1;i<=n;i++)
  // cout<<dp[i]<<" ";
  cout<<dp[n]<<endl;
  return 0;
}
