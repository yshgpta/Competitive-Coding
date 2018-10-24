#include<bits/stdc++.h>
using namespace std;
long long setbitcounter(long n){
  long long count=0;
  while(n){
    n &= (n-1);
    count++;
  }
  return count;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    long a;
    cin>>a;
    if(a<=2048)
    cout<<setbitcounter(a)<<endl;
    else{
      long n=a,rem,q;
      rem = n%2048;
      q = n/2048;
      cout<<q+setbitcounter(rem)<<endl;
    }
  }
  return 0;
}
