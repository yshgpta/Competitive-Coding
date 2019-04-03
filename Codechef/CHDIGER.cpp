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
 	int t;
  cin>>t;
  while(t--){
    string str;
    int d;
    cin>>str>>d;
    vector<int> v;
    int cnt=0;
    int min = 1;
    int index;
    int len = str.length();
    while(min<d && min<10){
      int start_index=0,end_index=0;
      for(int i=0;i<str.length();i++){
        if((str[i]-'0')==min){
          end_index = i;
          v.pb(min);
        }
      }
      if(end_index!=0)
      str.erase(str.begin()+start_index,str.begin()+end_index+1);
      min++;
    }
    cnt = len-v.size();
    for(int i=0;i<v.size();i++)
    cout<<v[i];


    while(cnt--)
    cout<<d;
    cout<<endl;
  }
 	return 0;
 }
