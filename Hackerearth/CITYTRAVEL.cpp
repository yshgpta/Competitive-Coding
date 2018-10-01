#include <bits/stdc++.h>
using namespace std;
queue <pair<int,int> > q;
bool compare(pair<int,int>& a,pair<int,int> &b){
  return a.first<b.first;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long int s,x,n;
  cin>>s>>x>>n;
  vector <pair <int,int> > arr;
  int num =n;
  while(n--){
    long a,b;
    cin>>a>>b;
    arr.push_back(make_pair(a,b));
  }
  sort(arr.begin(),arr.end(),compare);
  for(int i=0;i<arr.size();i++){
    q.push(arr[i]);
  }
  long val = s;
  long i=1,count=0;
  while(val>0){
    if(q.front().first==i){
      val -= q.front().second;
      count++;
      i++;
      q.pop();
    }else{
      val -= x;
      i++;
      count++;
    }
  }
  cout<<count<<"\n";
  return 0;
}
