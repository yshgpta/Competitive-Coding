#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    long long arr[n+1];
    vector<long long> sum(n+1,0);
    sum[0]=0;
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
      sum[i]=sum[i-1]+arr[i];
    }
    long s1,s2;
    s1=sum[k];
    s2=sum[n]-sum[n-k];
    cout<<max(abs(s1-(sum[n]-s1)),abs(s2-(sum[n]-s2)))<<endl;
  }
  return 0;
}
