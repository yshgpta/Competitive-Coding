#include<bits/stdc++.h>
using namespace std;
int main(){
  long n;
  cin>>n;
  map<long,long> x;
  map<long,long> y;
  map< pair<long,long>, long> xy;
  long a,b;
  int64_t counter(0);
  for(int i=0;i<n;i++){
    cin>>a>>b;
    if(x.count(a)>0){
      counter += x[a];
      x[a]++;
    }else{
      x[a]=1;
    }
    if(y.count(b)>0){
      counter += y[b];
      y[b]++;
    }else{
      y[b]=1;
    }
    pair<long,long> x_y = make_pair(a,b);
    if(xy.count(x_y)>0){
      counter -= xy[x_y];
      xy[x_y]++;
    }else{
      xy[x_y]=1;
    }
  }
  cout<<counter;
  return 0;
}
