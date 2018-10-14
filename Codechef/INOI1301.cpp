#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long dp1[n+1],dp2[n+2];
    long long arr[n+1];
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    dp1[1]=arr[1];
    dp1[2]=arr[1]+arr[2];
    for(int i=3;i<=n;i++){
      dp1[i]=arr[i]+max(dp1[i-1],dp1[i-2]);
    }
    dp2[k]=0;
    dp2[k-1]=0;
    for(int i=k+1;i<=n;i++){
      dp2[i]=arr[i]+max(dp2[i-1],dp2[i-2]);
    }
    long long ans = dp1[k]+dp2[k]-arr[k];
    for(int i=k;i<=n;i++){
      ans=max(ans,dp1[i]+dp2[i]-arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}
