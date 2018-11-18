#include<bits/stdc++.h>
using namespace std;
long arr[10005];
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    long long sum[n]={0};
    cin>>arr[0];
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
      cin>>arr[i];
      sum[i]=sum[i-1]+arr[i];
    }
    long long sum1,sum2,val,max=0;
    for(int i=0;i<n-1;i++){
      sum1=sum[i];
      sum2=sum[n-1]-sum[i];
      val=abs(sum1-sum2);
      if(val>max)
      max=val;
    }
    cout<<max<<endl;
  }
  return 0;
}
