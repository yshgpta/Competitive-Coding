#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    vector <int> arr;
    int a;
    for(int i=0;i<n;i++){
      cin>>a;
      arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
      if(arr[i]<=k)
      continue;
      else{
        for(int j=i+1;j<n;j++){
          if(min(arr[i],arr[j])>k){
            arr[i]--;
            arr[j]--;
          }
        }
      }
    }
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=arr[i];
    }
    cout<<sum<<endl;
  }
  return 0;
}
