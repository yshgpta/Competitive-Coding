#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n],min=100005,sum=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      sum += arr[i];
      if(arr[i]<min)
      min=arr[i];
    }
    int result = sum-n*min;
    cout<<result<<endl;
  }
}
