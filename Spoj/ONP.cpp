#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    stack<char> stk;
    for(int i=0;i<str.length();i++){
      if(isalpha(str[i]))
      cout<<str[i];
      else if(str[i]==')'){
        cout<<stk.top();
        stk.pop();
      }else if(str[i]!='('){
         stk.push(str[i]);
      }
    }
    cout<<endl;
  }
  return 0;
}
