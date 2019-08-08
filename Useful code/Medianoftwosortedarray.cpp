//My solution
//Binary Search:Median of two sorted array of different size
//Tushar Roy
#include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define vi vector<ll>
 #define vvi vector<vi>
 #define pii pair<ll,ll>
 #define mp make_pair
 #define pb push_back
 #define INF 1000000000000000
 #define MOD 1000000007
 #define ff first
 #define ss second
 #define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 vi arr1={23,26,31,35};
 vi arr2={3,5,7,9,11,16};

double f(vi &srr, vi &lrr){
  int low=0;
  int high=srr.size();
  int s1=srr.size(),s2=lrr.size();
  double median;
  while(high>=low){
    int p1 = (high+low)/2;
    int p2 = (s1+s2+1)/2-p1;
    if(p1==0){
      if((s1+s2)%2==0)
      median = (double)(lrr[p2-1]+min(srr[p1],lrr[p2]))/2.0;
      else
      median = lrr[p2-1];
      break;
    }else if(p2==0){
      if((s1+s2)%2==0)
      median = (double)(srr[p1-1]+min(srr[p1],lrr[p2]))/2.0;
      else
      median = srr[p1-1];
      break;
    }else{
      if(srr[p1-1]>lrr[p2])
      high=p1-1;
      else if(lrr[p2-1]>srr[p1])
      low=p1+1;
      else{
        if((s1+s2)%2==0)
        median = (double)(max(srr[p1-1],lrr[p2-1])+min(srr[p1],lrr[p2]))/2.0;
        else
        median = max(srr[p1-1],lrr[p2-1]);
        break;
      }
    }
  }
  return median;
}

 int main(){
 	FastIO
 	if(arr1.size()<arr2.size()){
    cout<<f(arr1,arr2);
  }else{
    cout<<f(arr2,arr1);
  }
 	return 0;
 }
