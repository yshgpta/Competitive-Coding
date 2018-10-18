#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long fact[200010];
void precompute(){
  fact[0]=1;
  fact[1]=1;
  for(int i=2;i<=200001;i++)
  fact[i]=(i*fact[i-1])%mod;
}
long long pwr(long long base,long long n){
  if(n==0)
  return 1;
  if(n==1)
  return base;
  long long halfn = pwr(base,n/2);
  halfn = (halfn * halfn)%mod;
  if(n%2==0)
  return halfn;
  else
  return (halfn * base)%mod;
}
int main(){
  precompute();
  int t;
  cin>>t;
  for(int j=1;j<=t;j++){
    long long  x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    long long x = x2-x1;
    long long y = y2-y1;
    long long z=0;
    for(int i=0;i<=min(x,y);i++){
      long long k=1;
      k=(k*((fact[x+y-i]*pwr(fact[x],mod-2))%mod * pwr(fact[y-i],mod-2))%mod )%mod;
      k=(k*((((fact[x] * pwr(fact[i],mod-2))%mod) * pwr(fact[x-i],mod-2))%mod) )%mod;
      z=(z+k)%mod;
    }
    cout<<"Case "<<j<<": "<<z<<endl;
  }
  return 0;
}
