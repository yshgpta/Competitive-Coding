#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long n,k;
    cin>>n>>k;
    long a;
    for(int i=0;i<n;i++){
      cin>>a;
      if(a<=k){
        cout<<1;
        k-=a;
      }else{
        cout<<0;
      }
    }
    cout<<endl;
  }
  return 0;
}
