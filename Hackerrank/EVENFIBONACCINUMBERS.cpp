#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long n;
    cin>>n;
    int i=0;
    long long a,b,c;
    a=1;b=1;c=2;
    long long sum=0;
    while(c<n){
      sum+=c;
      a=b+c;
      b=a+c;
      c=a+b;
    }
    cout<<sum<<endl;
  }
  return 0;
}
