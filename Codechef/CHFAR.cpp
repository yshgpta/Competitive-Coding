#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    int a,count=0;
    for(int i=0;i<n;i++){
      cin>>a;
      if(a>1)
      count++;
    }
    if(count<=k)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
  return 0;
}
