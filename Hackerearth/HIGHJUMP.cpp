#include<bits/stdc++.h>
using namespace std;
int main(){
  long n,m,l,a;
  cin>>n>>m>>l>>a;
  vector <pair <int,int> > arr;
  long x,y;
  long num=n;
  while(n--){
    cin>>x>>y;
    if(y>=m){
        cout<<"No"<<endl;
        exit(0);
    }
    arr.push_back(make_pair(x,y));
  }
  float y2,x2;
  float x1,xa,xb,dis,x2a,y2a,x2b,y2b,h;
  sort(arr.begin(),arr.end());
  for(int i=0;i<num-1;i++){
      x2a=arr[i].first;
      y2a=arr[i].second;
      xa = (y2a + a*x2a)/a;
      long val1,val2,mid;
      val1=xa-x2a;
      x2b=arr[i+1].first;
      y2b=arr[i+1].second;
      xb = (y2b + a*x2b)/a;
      val2=xb-x2b;
      dis = x2b-x2a;
      if(val1+val2>dis){
          mid=(x2a+x2b)/2;
          h=y2b+x2b*a-mid*a;
          if(h>=m){
              cout<<"No"<<endl;
              exit(0);
          }
      }

  }
  
  y2 = arr[num-1].second;
  x2 = arr[num-1].first;
  x1 = (y2 + a*x2)/a;
  if(x1<=l)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
