#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(b==0)
  return a;
  return gcd(b,a%b);
}
long long power(long long base,long long n,long long M){
  if(n==0)
  return 1;
  if(n==1)
  return base;
  long long halfn = power(base,n/2,M);
  if(n%2==0)
  return (halfn*halfn)%M;
  else
  return ((halfn*halfn)%M*base)%M;
}
int main(){
  long long MOD = 1e9+7;
  int n;
  cin>>n;
  int arr[n];
  long long f,g;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  g=arr[0],f=arr[0];
  for(int i=1;i<n;i++){
    g=gcd(arr[i],g);
    f = (f*arr[i])%MOD;
  }
  cout<<power(f,g,MOD);
}
