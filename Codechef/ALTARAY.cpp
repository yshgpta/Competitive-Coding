#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<long> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int> dp(n,1);
    for(int i=n-2;i>=0;i--){
      if(arr[i+1]>0){
        if(arr[i]<0)
        dp[i]+=dp[i+1];
      }else{
        if(arr[i]>0)
        dp[i]+=dp[i+1];
      }
    }
    for(int i=0;i<n;i++)
    cout<<dp[i]<<" ";
    cout<<endl;
  }
  return 0;
}
