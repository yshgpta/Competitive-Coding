#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
  if(b==0)
  return a;
  else
  return gcd(b,a%b);
}
long long lcm(long long a,long long b){
  long long val = (a*b)/gcd(a,b);
  return val;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    long long k,n,a,b;
    cin>>n>>a>>b>>k;
    long long l = lcm(a,b);
    long long val = (n/a) + (n/b) - 2*(n/l);
    if(val>=k)
    cout<<"Win"<<endl;
    else
    cout<<"Lose"<<endl;
  }
  return 0;
}
