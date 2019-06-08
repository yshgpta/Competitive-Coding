#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long bl,br,tl,b;
    cout<<"Q"<<" "<<0<<" "<<0<<endl;
    cin>>bl;
    cout<<"Q"<<" "<<0<<" "<<MAX<<endl;
    cin>>tl;
    tl = tl - MAX;
    cout<<"Q"<<" "<<MAX<<" "<<0<<endl;
    cin>>br;
    br = br -MAX;
    long long val1 = (bl-br)/2;
    cout<<"Q"<<" "<<val1<<" "<<0<<endl;
    cin>>b;
    long long a = bl-b;
    long long c = b - br;
    long long d = a -tl;
    cout<<"A"<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cin>>a;
    if(a>0)
    continue;
    else
    break;
  }
  return 0;
}
