#include<bits/stdc++.h>
using namespace std;

 int main(){
   long long n,s;
   cin>>n>>s;
   vector<long long> arr(n+1);
   for(int i=1;i<=n;i++)
   cin>>arr[i];
   long long k,sum,val,ans=0,cost=0;
   long long low=0,high=n;
   while(low<=high){
     vector<long long> res;
     sum=0;
     k=(low+high)/2;
     for(int i=1;i<=n;i++){
       val = arr[i]+k*i;
       res.push_back(val);
     }
     sort(res.begin(),res.end());
     for(int i=0;i<k;i++){
       sum+=res[i];
     }
     if(sum==s){
       cout<<k<<" "<<sum;
       return 0;
     }
     if(sum>s)
     high = k-1;
     else{
       low = k+1;
       ans = k;
       cost = sum;
     }
   }
   cout<<ans<<" "<<cost;
   return 0;
 }
