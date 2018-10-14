#include<bits/stdc++.h>
using namespace std;
// int sum1(int *arr,int n,int k,int *j_ref){
//   if(k>n)
//   return 0;
//   int val = max(arr[k]+max(sum1(arr,n,k+1,j_ref),sum1(arr,n,k+2,j_ref)),max(sum1(arr,n,k+1,j_ref),sum1(arr,n,k+2,j_ref)));
//   int m=k;
//   if(m>*j_ref)
//   *j_ref=m;
//   return val;
// }
// int sum2(int *arr,int n,int k){
//   if(k<n)
//   return 0;
//   int val = max(arr[k]+max(sum2(arr,n,k-1),sum2(arr,n,k-2)),max(sum2(arr,n,k-1),sum2(arr,n,k-2)));
//   return val;
// }
//
// int main(){
//   int n,k;
//   cin>>n>>k;
//   int arr[n];
//   for(int i=0;i<n;i++)
//   cin>>arr[i];
//   int j=-1;
//   cout<<sum1(arr,n-1,k,&j)+sum2(arr,0,j-3);
//   cout<<j;
// }
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
      ans=max(ans,dp1[i]+dp2[i]-arr[k]);
    }
    cout<<ans<<endl;
    return 0;
}
