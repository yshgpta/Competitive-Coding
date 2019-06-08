#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



 int main(){
 	FastIO
 	string s,t;
  cin>>s>>t;
  vi hash(60,0);
  for(int i=0;i<t.length();i++){
    hash[t[i]-'A']++;
  }
  ll cntn=0,cntp=0;
  for(int i=0;i<s.length();i++){
    if(hash[s[i]-'A']>0){
      cntp++;
      hash[s[i]-'A']--;
      s[i]='-';
    }
  }
  for(int i=0;i<s.length();i++){
    if(s[i]!='-'){
      if(isupper(s[i]) && hash[tolower(s[i])-'A']>0){
        cntn++;
        hash[tolower(s[i])-'A']--;
      }else if(islower(s[i]) && hash[toupper(s[i])-'A']>0){
        cntn++;
        hash[toupper(s[i])-'A']--;
      }
    }
  }
  cout<<cntp<<" "<<cntn;
 	return 0;
 }
