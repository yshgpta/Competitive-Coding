#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string str;
  cin>>str;
  int counta=0,countd=0;
  for(int i=0;i<n;i++){
    if(str[i]=='A')
    counta++;
    else
    countd++;
  }
  if(counta==countd)
  cout<<"Friendship";
  else if(counta>countd)
  cout<<"Anton";
  else
  cout<<"Danik";
  return 0;
}
