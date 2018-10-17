#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    long long arr_sum[n];
    cin>>arr[0];
    arr_sum[0]=arr[0];
    for(int i=1;i<n;i++){
      cin>>arr[i];
      arr_sum[i] =arr_sum[i-1]+arr[i];
    }
    if(arr[0]>=n-1){
      cout<<"1"<<endl;
      continue;
    }
    long day=0,i=0;
    while(i<n-1)
		{
			i+=arr_sum[i];
			day++;
		}
    cout<<day<<endl;
  }
  return 0;
}
