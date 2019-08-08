#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long num;
    cin>>num;
    long long ngp = log2(num)+1;
    long long ans = num*(num+1)/2-2*(pow(2,ngp)-1);
    cout<<ans<<endl;
  }
  return 0;
}
