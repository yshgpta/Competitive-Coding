#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long n,k;
    cin>>n>>k;
    long arr[n];
    long sum=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum += arr[i];
    }
    if(sum<=k)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
  }
  return 0;
}
