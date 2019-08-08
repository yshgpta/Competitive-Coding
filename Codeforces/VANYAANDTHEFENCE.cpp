#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,h;
  cin>>n>>h;
  int a,count=0;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a<=h)
    count++;
    else
    count+=2;
  }
  cout<<count;
  return 0;
}
