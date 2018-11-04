#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,x;
    char ch;
    cin>>n>>x;
    cin>>ch;
    char ch1,ch2,ch3,ch4,ch5;
    for(int i=0;i<x;i++){
      cin>>ch1>>ch2>>ch3>>ch4>>ch5;
    }
    int count=0;
    for(int i=x;i<n;i++){
      cin>>ch1>>ch2>>ch3>>ch4>>ch5;
      if(ch3==ch || ch5==ch)
      count++;
    }
    cout<<count<<endl;
  }
  return 0;
}
