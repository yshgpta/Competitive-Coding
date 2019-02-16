#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++){
      cin>>str[i];
    }
    bool pri[26];
    memset(pri,true,sizeof(pri));
    for(int i=0;i<n;i++){
      bool sec[26]={false};
      for(int j=0;str[i][j];j++){
        if(pri[str[i][j]-'a'])
        sec[str[i][j]-'a']=true;
      }
      memcpy(pri,sec,26);
    }
    long count=0;
    for(int i=0;i<26;i++)
    if(pri[i]==true)
    count++;
    cout<<count<<endl;
  }
  return 0;
}
