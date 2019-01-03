// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int n;
//   cin>>n;
//   vector<int> arr(n+1);
//   for(int i=1;i<=n;i++){
//     cin>>arr[i];
//     arr[i]+=i;
//   }
//   int maxelement = *max_element(arr.begin()+1,arr.end());
//   cout<<maxelement<<" ";
//   for(int i=1;i<n;i++){
//     for(int j=1;j<=n-i;j++)
//     arr[j]++;
//     arr[n-i+1]-=n-1;
//     for(int j=n-i+2;j<=n;j++)
//     arr[j]++;
//     maxelement = *max_element(arr.begin()+1,arr.end());
//     cout<<maxelement<<" ";
//   }
//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;

long long arr[200005];
multiset<long long> pq;
multiset<long long> :: iterator it;

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    pq.insert(arr[i]+i);
  }
  for(int i=1;i<=n;i++){
    if(i!=1)
    cout<<" ";
    it=pq.end();
    cout<<*(--it)+i-1;
    it = pq.find(arr[n-i+1]+n-i+1);
    pq.erase(it);
    pq.insert(arr[n-i+1]+n-i+1-n);
  }
  return 0;
}
