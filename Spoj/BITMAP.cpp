#include<bits/stdc++.h>
#define INF 100000
using namespace std;
int a[190][190];
int n,m;

int bfs(int i,int j){
  queue<int> q;
  q.push(i);
  q.push(j);
  a[i][j]=0;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    int y = q.front();
    q.pop();
    int dist = a[x][y]+1;
    if(y-1>=0 && dist < a[x][y-1]){
      q.push(x);
      q.push(y-1);
      a[x][y-1]=dist;
    }
    if(y+1<n && dist<a[x][y+1]){
      q.push(x);
      q.push(y+1);
      a[x][y+1] = dist;
    }
    if(x+1<m && dist<a[x+1][y]){
      q.push(x+1);
      q.push(y);
      a[x+1][y] = dist;
    }
    if(x-1>=0 && dist<a[x-1][y]){
      q.push(x-1);
      q.push(y);
      a[x-1][y] = dist;
    }
  }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    vector<pair<int,int> > v;
    cin>>m>>n;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        char ch;
        cin>>ch;
        if(ch=='1'){
          a[i][j] = -INF;
          v.push_back(make_pair(i,j));
        }
        else{
          a[i][j] = INF;
        }
      }
    }

    for(int i=0;i<v.size();i++)
    bfs(v[i].first,v[i].second);

    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
}
