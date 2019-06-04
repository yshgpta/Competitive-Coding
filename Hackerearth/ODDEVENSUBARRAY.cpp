#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int hash_p[n+1]={0},hash_n[n+1]={0};
  hash_p[0]=1;
  long long diff=0, ans=0;
  for(int i=0;i<n;i++){
    if(arr[i]&1==1)
    diff++;
    else
    diff--;
    if(diff<0){
      ans += hash_n[-diff];
      hash_n[-diff]++;
    }else{
      ans += hash_p[diff];
      hash_p[diff]++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
