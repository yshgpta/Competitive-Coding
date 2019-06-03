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
    long n,k;
    cin>>n>>k;
    vi arr(n);
    vector< multiset<ll> > a;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    ll res=0;
    for(int i=0;i<n;i++){
      multiset<ll> b;
      for(int j=i;j<n;j++){
        b.insert(arr[j]);
        double len = b.size();
        double m = ceil(k/len);
        int index = ceil(k/m)-1;
        multiset<ll> :: reverse_iterator it = b.rbegin();
        for(int l=1;l<=len-index;l++)
        it++;
        // advance(it,index);
        int x = *it;
        int f = b.count(x);
        if(b.count(f)>0)
          res++;
      }
    }
    cout<<res<<endl;
  }
 	return 0;
 }
