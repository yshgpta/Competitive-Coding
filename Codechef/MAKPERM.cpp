#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    long hash[100005]={0};
    int n;
    cin>>n;
    long a;
    for(int i=0;i<n;i++){
      cin>>a;
      if(a>100000)
      continue;
      else{
        hash[a]++;
      }
    }
    long count=0;
    for(int i=1;i<=n;i++){
      if(hash[i]==0)
      count++;
    }
    cout<<count<<endl;
  }
  return 0;
}
