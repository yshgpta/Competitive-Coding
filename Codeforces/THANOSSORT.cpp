#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define mp make_pair
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 bool isSorted(vi &arr,int l,int r){
   int flag=1;
   for(int i=l;i<r-1;i++){
     if(arr[i]>arr[i+1]){
       flag=0;
       break;
     }
   }
   if(flag==0)
   return false;
   else
   return true;
 }

 int main(){
 	FastIO
 	int n;
  cin>>n;
  vi arr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int low=0,high=arr.size();
  while(!isSorted(arr,low,high)){
    if(low>high)
    break;
    int mid = (low+high)/2;
    high=mid;
  }
  int count1= high-low;
  low=0,high=arr.size();
  while(!isSorted(arr,low,high)){
    if(low>high)
    break;
    int mid = (low+high)/2;
    low=mid;
  }
  int count2= high-low;
  int res = max(count1,count2);
  if(res==0)
  cout<<1;
  else
  cout<<res;
 	return 0;
 }
