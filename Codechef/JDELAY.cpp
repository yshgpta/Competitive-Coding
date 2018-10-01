#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int num=n;
    vector< pair<int,int> > arr;
    int a,b,d,cnt=0;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      arr.push_back(make_pair(a,b));
      d = arr[i].second-arr[i].first;
      if(d>5)
      cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}
