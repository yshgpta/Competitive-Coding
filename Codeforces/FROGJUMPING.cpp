#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long a,b,k,rem,left,res;
      cin>>a>>b>>k;
      res=(a-b)*(k/2);
      if(k%2!=0){
        res+=a;
      }
    cout<<res<<endl;
  }
  return 0;
}
