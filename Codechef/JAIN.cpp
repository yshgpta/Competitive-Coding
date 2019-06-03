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
    vi hash(32,0);
    for(int i=0;i<n;i++){
      string str;
      set<char> st;
      cin>>str;
      for(int j=0;j<str.length();j++){
        st.insert(str[j]);
      }
      int sum=0;
      for(auto it=st.begin();it!=st.end();it++){
        switch (*it) {
          case 'a':
            sum+=16;
            break;
          case 'e':
            sum+=8;
            break;
          case 'i':
            sum+=4;
            break;
          case 'o':
            sum+=2;
            break;
          case 'u':
            sum+=1;
            break;
        }
      }
      hash[sum]++;
    }
    ll cnt = 0;
    vvi v ={{0},{30,31},{29,31},{28,29,30,31},{27,31},{26,27,30,31},{25,27,29,31},{24,25,26,27,28,29,30,31},{23,31},{22,23,30,31},{21,23,29,31},
            {20,21,22,23,28,29,30,31},{19,23,27,31},{18,19,22,23,26,27,30,31},{17,19,21,23,25,27,29,31},{16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},{15,31},{14,15,30,31},
            {13,15,29,31},{12,13,14,15,28,29,30,31},{11,15,27,31},{10,11,14,15,26,27,30,31},{9,11,13,15,25,27,29,31},{8,9,10,11,12,13,14,15,24,25,26,27,28,29,30,31},
            {7,15,23,31},{6,7,14,15,22,23,30,31},{5,7,13,15,21,23,29,31},{4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31},{3,7,11,15,19,23,27,31},{2,3,6,7,10,11,14,15,18,19,22,23,26,27,30,31},
          {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}};
    for(int i=1;i<32;i++){
      if(hash[i]!=0){
        for(int j=0;j<v[i].size();j++){
          cnt += hash[i]*hash[v[i][j]];
        }
      }
    }
    ll extra = ((hash[31]-1)*hash[31])/2;
    ll res = cnt/2 + extra;
    cout<<res<<endl;
  }
 	return 0;
 }
