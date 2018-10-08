#include <bits/stdc++.h>
using namespace std;

int main(){
  long long MOD = 1000000007;
  int t;
  cin>>t;
  unsigned long long n,ans;
  while(t--){
    cin>>n;
    n = n%MOD;
    ans = (2*n)%MOD;
    ans = ans-1;
    ans = (ans*n)%MOD;
    cout<<ans<<endl;
  }
}
