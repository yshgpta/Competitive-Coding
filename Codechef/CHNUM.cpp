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
    int n;
    cin>>n;
    long long arr[n];
    long long sump=0,sumn=0;
    int np=0,nn=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(arr[i]<0){
        sumn+=abs(arr[i]);
        nn++;
      }else{
        sump+=arr[i];
        np++;
      }
    }
    if(np==0 || nn==0){
      if(np==0)
      cout<<nn<<" "<<nn<<endl;
      else
      cout<<np<<" "<<np<<endl;
    }else
    cout<<max(np,nn)<<" "<<min(np,nn)<<endl;
  }
 	return 0;
 }
