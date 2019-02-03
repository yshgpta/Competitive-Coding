#include<bits/stdc++.h>
using namespace std;

vector<long> arr(300005);
map<long,long> mp;

map<long,long> maxSumMap(int size){
  long max_so_far = arr[0];
  long curr_max = arr[0];
   for (int i = 1;i<size;i++){
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
        if(curr_max==max_so_far){
          if(mp.find(curr_max)!=mp.end()){
            mp[curr_max]++;
          }else{
            mp.insert({curr_max,1});
          }
        }
   }
   if(mp.find(max_so_far)!=mp.end())
   return mp;
   else{
     mp.insert({max_so_far,1});
     return mp;
   }
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  map<long,long> m;
  m = maxSumMap(n);
  map<long,long> :: iterator it;
  it = m.end();
  it--;
  if(it->first >= 0)
  cout<<it->first<<" "<<it->second;
  else
  cout<<"0"<<" "<<"0";
  return 0;
}
