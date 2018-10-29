#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  map<int,int> mm;
  mm[2010]=1;
  mm[2015]=2;
  mm[2016]=3;
  mm[2017]=4;
  mm[2019]=5;
  while(t--){
    int n;
    cin>>n;
    if(mm.find(n)!=mm.end())
    cout<<"HOSTED"<<endl;
    else
    cout<<"NOT HOSTED"<<endl;
  }
  return 0;
}
