//ysh_gpta
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define vpii vector<pair<ll,ll> >
 #define mp make_pair
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
    int n;
    cin>>n;
    string str;
    cin>>str;
    int flag=0;
    for(int i=0;i<n;i++){
      if(str[i]=='8' && (n-i)>=11){
        flag=1;
        break;
      }
    }
    if(flag==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
 	return 0;
 }
