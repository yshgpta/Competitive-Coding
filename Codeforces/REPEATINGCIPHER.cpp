#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string str;
  cin>>str;
  int j=1;
  for(int i=0;i<n;){
    cout<<str[i];
    i+=j;
    j++;
  }
  return 0;
}
