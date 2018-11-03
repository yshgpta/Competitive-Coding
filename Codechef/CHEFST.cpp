#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long n1,n2,m;
    cin>>n1>>n2>>m;
    long long val = (m*m+m)/2;
    if(n1>val && n2>val)
    cout<<n1+n2-2*val<<endl;
    else
    cout<<n1+n2-2*min(n1,n2)<<endl;
  }
  return 0;
}
