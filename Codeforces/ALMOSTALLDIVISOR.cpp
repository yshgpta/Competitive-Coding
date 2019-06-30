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
    vi arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll max = arr[n-1];
    ll min = arr[0];
    int flag=0;
    for(int i=0;i<n-1;i++){
      if((max*min)%arr[i]!=0){
        flag=1;
        break;
      }
    }
    vi div;
    ll num = min*max;
    int flag1=0;
    if(flag==0){
      for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
          if(i==num/i)
          div.pb(i);
          else{
            div.pb(i);
            div.pb(num/i);
          }
        }
      }
      sort(div.begin(),div.end());
      if(div.size()==arr.size()){
        for(int i=0;i<div.size();i++){
          if(div[i]!=arr[i])
          flag1=1;
        }
      }else{
        flag1=1;
      }
      if(flag1==0)
      cout<<max*min<<endl;
      else
      cout<<-1<<endl;
    }
    else
    cout<<-1<<endl;
  }
 	return 0;
 }
