#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin>>n;
  long long arr[100001]={0};
  long long dp[100001];
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    arr[a]++;
  }
  dp[0]=0;
  dp[1]=arr[1];
  for(int i=2;i<100001;i++){
    dp[i]=max(dp[i-1],(dp[i-2]+i*arr[i]));
  }
  cout<<dp[100000]<<endl;
  return 0;
}
