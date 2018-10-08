#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int fast_pow(long long base,long long n,long long M){
    if(n==0)
    return 1;
    if(n==1)
    return base;
    long long half_n = fast_pow(base,n/2,M);
    if(n%2==0)
    return (half_n*half_n)%M;
    else
    return ((half_n*half_n)%M*base%M)%M;
}
int fermate_pow(long long n,long long M){
    return fast_pow(n,M-2,M);
}
int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;
    //minimum
    unsigned long long comb;
    comb = (n-1)/2;
    long long minx = (comb*comb)%MOD;
    minx = (minx*n)%MOD;
    //maximum
    long long six_inverse = fermate_pow(6,MOD);
    unsigned long long maxx;
    maxx = (n*(n-1))%MOD;
    maxx = (maxx*(2*n-1))%MOD;
    maxx =(maxx*six_inverse)%MOD;
    cout<<minx<<" "<<maxx<<endl;
  }
}
