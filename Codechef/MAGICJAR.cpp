#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    long long arr[n];
    long long sum=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum += arr[i]-1;
    }
    cout<<sum+1<<endl;
  }
  return 0;
}
