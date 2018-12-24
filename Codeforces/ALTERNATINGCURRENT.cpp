#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  cin>>str;
  stack<int> st;
  for(int i=0;i<str.length();i++){
    if(st.empty() || st.top()!=str[i])
    st.push(str[i]);
    else
    st.pop();
  }
  if(st.empty())
  cout<<"Yes";
  else
  cout<<"No";
  return 0;
}
