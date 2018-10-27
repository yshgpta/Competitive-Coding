// Solution got TLE.
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     long n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     long temp_i=-1,temp_j=-1;
//     for(int i=0;i<n-1;i++){
//       for(int j=i+1;j<n;j++)
//       if(arr[i]<arr[j]){
//         temp_i=i;
//         temp_j=j;
//       }
//     }
//     if(temp_i==-1){
//       cout<<"-1"<<endl;
//       continue;
//     }
//     swap(arr[temp_i],arr[temp_j]);
//     reverse(arr+temp_i+1,arr+n);
//     for(int i=0;i<n;i++)
//     cout<<arr[i];
//     cout<<endl;
//   }
//   return 0;
// }
// Solution Accepted
#include <bits/stdc++.h>
using namespace std;
int main(){
   int t,n;
   cin>>t;
   while(t--){
      cin>>n;
      int arr[n];
      for(int i=0; i<n ; ++i)
         cin>>arr[i];
      if(next_permutation(arr,arr+n))
         for(int i=0; i<n ; ++i)
            cout<<arr[i];
      else
         cout<<"-1";
      cout<<endl;
   }
   return 0;
}
