#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string str;
  cin>>str;
  string s="";
  s+=str[0];
  str.erase(str.begin()+0);
  int len;
  while(!str.empty()){
    len = str.length();
    if(len%2==0){
      s.insert(s.begin()+0,str[0]);
    }
    else{
      s+=str[0];
    }
    str.erase(str.begin()+0);
  }
  cout<<s;
  return 0;
}
