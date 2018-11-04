#include<bits/stdc++.h>
using namespace std;
int main(){
  long n,q;
  cin>>n>>q;
  vector< map<long,long> > arr(n+1);
  for(int k=0;k<q;k++){
    long a,i,j,l,r;
    cin>>a;
    if(a==1){
      cin>>j>>i;
      if(arr[j].find(i)!=arr[j].end()){
        map<long,long> :: iterator it;
        it=arr[j].find(i);
        arr[j].erase(it);
      }
      else
      arr[j].insert(make_pair(i,1));
    }
    else{
      cin>>l>>r;
      long b[r-l+2]={0};
      long max=0;
      if(arr[l].size()==3){
        b[0]=1;
        max=1;
      }
      for(int m=l+1;m<=r;m++){
        if(arr[m].size()==3){
          b[m-l]=b[m-l-1]+1;
          if(b[m-l]>max)
          max=b[m-l];
        }
      }
      cout<<max<<endl;
    }
  }
  return 0;
}
