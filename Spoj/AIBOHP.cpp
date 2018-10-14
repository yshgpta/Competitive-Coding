#include<bits/stdc++.h>
#include<string.h>
using namespace std;
long strl[6110][6110];
string str;
long palindrome(long l,long r){
  if(l>=r)
  return 0;
  if(strl[l][r]!=-1)
  return strl[l][r];
  if(str[l]==str[r])
  strl[l][r]=palindrome(l+1,r-1);
  else
  strl[l][r]=1+min(palindrome(l+1,r),palindrome(l,r-1));
  return strl[l][r];
}

int main(){
  int t;
  cin>>t;
  while(t--){
    memset(strl,-1,sizeof(strl));
    getline(cin,str);
    cout<<palindrome(0,str.length()-1)<<endl;
  }
  return 0;
}
