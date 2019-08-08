#include<bits/stdc++.h>
using namespace std;

long strcp(string str1,string str2){
  long count=0;
  int i;
  for(i=0;i<str1.length()-2;i+=3){
    if(str1[i]!=str2[i])
    count++;
    if(str1[i+1]!=str2[i+1])
    count++;
    if(str1[i+2]!=str2[i+2])
    count++;
  }
  while(i<str1.length()){
    if(str1[i]!=str2[i])
    count++;
    i++;
  }
  return count;
}

int main(){
  string seq[]={"RGB","RBG","GRB","GBR","BRG","BGR"};
  int len;
  cin>>len;
  string str;
  cin>>str;
  if(len==1){
    cout<<0<<endl;
    cout<<str;
    return 0;
  }
  if(len==2){
    if(str.compare("RR")==0||str.compare("BB")==0||str.compare("GG")){
      cout<<1<<endl;
      if(str[0]=='R')
      cout<<"RG";
      if(str[0]=='G')
      cout<<"GB";
      if(str[0]=='B')
      cout<<"BR";
      return 0;
    }else{
      cout<<0<<endl;
      cout<<str;
      return 0;
    }
  }
  string str1="",str2="",str3="",str4="",str5="",str6="";
  int i=2;
  int rem = len%3;
  while(i<len){
    str1=str1+seq[0];
    str2=str2+seq[1];
    str3=str3+seq[2];
    str4=str4+seq[3];
    str5=str5+seq[4];
    str6=str6+seq[5];
    i+=3;
  }
  if(rem==1){
    str1=str1+"R";
    str2=str2+"R";
    str3=str3+"G";
    str4=str4+"G";
    str5=str5+"B";
    str6=str6+"B";
  }
  if(rem==2){
    str1=str1+"RG";
    str2=str2+"RB";
    str3=str3+"GR";
    str4=str4+"GB";
    str5=str5+"BR";
    str6=str6+"BG";
  }
  vector<pair<int,string> > v;
  v.push_back(make_pair(strcp(str,str1),str1));
  v.push_back(make_pair(strcp(str,str2),str2));
  v.push_back(make_pair(strcp(str,str3),str3));
  v.push_back(make_pair(strcp(str,str4),str4));
  v.push_back(make_pair(strcp(str,str5),str5));
  v.push_back(make_pair(strcp(str,str6),str6));
  sort(v.begin(),v.end());
  cout<<v[0].first<<endl;
  cout<<v[0].second;
  return 0;
}
