#include<bits/stdc++.h>
using namespace std;
int checker(string str){
  int pcount=0,count=0;
  for(int i=0;i<str.length();i++){
    if(str[i]=='{')
    count++;
    else{
      count--;
      if(count<0){
        pcount++;
        count=1;
      }
    }
  }
  int ans = pcount+count/2;
  return ans;
}
int main(){
  string str;
  cin>>str;
  int i=1;
  while(str[0]!='-'){
    cout<<i<<". "<<checker(str)<<endl;
    cin>>str;
    i++;
  }
  return 0;
}
