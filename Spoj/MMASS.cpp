#include<bits/stdc++.h>
using namespace std;
int getVal(char ch){
  switch (ch) {
    case 'H': return 1;
    case 'C': return 12;
    case 'O': return 16;
  }
  return 0;
}
int main(){
  string str;
  cin>>str;
  stack<int> stk;
  int v;
  for(int i=0;i<str.length();i++){
    if(isdigit(str[i])){
      v=stk.top();
      stk.pop();
      stk.push(v*(str[i]-'0'));
    }else if(str[i]=='(')
    stk.push(-1);
    else if(str[i]==')'){
      v=0;
      while(!stk.empty() && stk.top()!=-1){
        v+=stk.top();
        stk.pop();
      }
      stk.pop();
      stk.push(v);
    }
    else
    stk.push(getVal(str[i]));
  }
  v=0;
  while(!stk.empty()){
    v+=stk.top();
    stk.pop();
  }
  cout<<v<<endl;
  return 0;
}
