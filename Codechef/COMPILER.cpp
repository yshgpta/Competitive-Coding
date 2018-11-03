#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    stack<char> stk;
    int count=0;
    for(int i=0;i<str.length();i++){
      if(str[i]=='<')
      stk.push(str[i]);
      else if(str[i]=='>'){
        if(!stk.empty())
        stk.pop();
        else
        break;
        if(stk.empty())
        count=i+1;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
