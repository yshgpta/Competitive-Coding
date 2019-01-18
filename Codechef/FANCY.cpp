#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  string str;
  getline(cin,str);
  while(t--){
    string str;
    getline(cin,str);
    vector<string> srr;
    for(int i=0;i<str.length();i++){
      if(str[i]==' ')
      continue;
      string s = "";
      s+=str[i];
      while(i+1<str.length() && str[i+1]!=' '){
        s+=str[i+1];
        i++;
      }
      srr.push_back(s);
    }
    if(find(srr.begin(),srr.end(),"not")!=srr.end())
    cout<<"Real Fancy"<<endl;
    else
    cout<<"regularly fancy"<<endl;
  }
  return 0;
}
