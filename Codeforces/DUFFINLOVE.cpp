#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin>>n;
  long long cnt=1;
  for(long long i=2;i*i<=n;i++){
    if(n%i==0){
      while(n%i==0)
      n/=i;
      cnt*=i;
    }
  }
  if(n>=2)
  cnt*=n;
  cout<<cnt;
  return 0;
}
