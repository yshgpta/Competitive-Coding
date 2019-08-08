#include<bits/stdc++.h>
using namespace std;
int main()
{
    int parent[100002];
    int color[100002];
    int n,c;
    cin>>n>>c;
    for(int i=2;i<=n;i++)
    cin>>parent[i];
    for(int i=1;i<=n;i++)
    cin>>color[i];
    for(int i=1;i<=n;i++){
      int current=i,ans=-1;
      c=color[i];
      while(current!=1){
        current=parent[current];
        if(color[current]==c){
          ans=current;
          break;
        }
      }
      cout<<ans<<" ";
    }
    return 0;
}
