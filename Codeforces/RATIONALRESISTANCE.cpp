#include<bits/stdc++.h>
using namespace std;
long long counter(long long a,long long b){
  if(a%b==0)
  return a/b;
  return a/b+counter(b,a%b);
}
int main(){
  long long a,b;
  cin>>a>>b;
  if(a>b)
  cout<<counter(a,b);
  else
  cout<<counter(b,a);
  return 0;
}
