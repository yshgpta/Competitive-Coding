#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
  if(a.first<b.first)
  return true;
  return false;
}
int main(){
  int num;
  cin>>num;
  vector <pair<int,int> > arr;
  int a;
  long long sum[num];
  for(int i=0;i<num;i++){
    cin>>a;
    arr.push_back(make_pair(a,i+1));
  }

  sort(arr.begin(),arr.end(),compare);
  sum[0]=arr[0].first;
  for(int i=1;i<num;i++){
    sum[i]=sum[i-1]+arr[i].first;
  }
  // for(int i=0;i<num;i++)
  // cout<<sum[i]<<" ";
  int count=0;
  vector<int> val;
  if((sum[num-2]-arr[num-2].first)==arr[num-2].first){
    count++;
    val.push_back(arr[num-1].second);
  }
  if((sum[num-1]-arr[num-1].first)!=arr[num-1].first){
    for(int i=0;i<num-1;i++){
      if(sum[num-2]-arr[i].first==arr[num-1].first){
        count++;
        val.push_back(arr[i].second);
      }
    }
  }
  cout<<count<<endl;
  if(count!=0){
    for(int i=0;i<count;i++){
    cout<<val[i]<<" ";
  }
  }

  return 0;
}
