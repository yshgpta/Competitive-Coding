//Giving TLE
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     multiset<long> pq;
//     multiset<long> :: iterator it;
//     int a;
//     cin>>a;
//     pq.insert(a);
//     while(a!=0){
//       cin>>a;
//       if(a==-1){
//         int numberOfElement = pq.size();
//         int val;
//         if(numberOfElement%2==1)
//           val=numberOfElement/2+1;
//         else
//           val=numberOfElement/2;
//         it=pq.begin();
//         advance(it,val-1);
//         cout<<*(it)<<endl;
//         pq.erase(it);
//       }
//       else
//       pq.insert(a);
//     }
//     cout<<endl;
//   }
//   return 0;
// }

//Gives TLE
// #include<bits/stdc++.h>
// using namespace std;
//
// void insertNumber(int a,priority_queue<int,vector<int>,greater<int> >& min_heap,priority_queue<int>& max_heap){
//   if(max_heap.size() == 0 || a<max_heap.top()){
//     max_heap.push(a);
//   }
//   else{
//     min_heap.push(a);
//   }
// }
// void rebalance(priority_queue<int,vector<int>,greater<int> >& min_heap,priority_queue<int>& max_heap){
//   int min_heap_length = min_heap.size();
//   int max_heap_length = max_heap.size();
//   if((max_heap_length - min_heap_length)>=2){
//     min_heap.push(max_heap.top());
//     max_heap.pop();
//   }
//   if((min_heap_length - max_heap_length)>=2){
//     max_heap.push(min_heap.top());
//     min_heap.pop();
//   }
// }
//
// int getmedian(priority_queue<int,vector<int>,greater<int> >& min_heap,priority_queue<int>& max_heap){
//   int min_heap_length = min_heap.size();
//   int max_heap_length = max_heap.size();
//   if(min_heap_length <= max_heap_length){
//     int val = max_heap.top();
//     max_heap.pop();
//     return val;
//   }else{
//     int val = min_heap.top();
//     min_heap.pop();
//     return val;
//   }
// }
//
//
// int main(){
//   int t;
//   cin>>t;
//   while(t--){
//     priority_queue<int> max_heap;
//     priority_queue<int,vector<int>,greater<int> > min_heap;
//     int a;
//     cin>>a;
//     while(a!=0){
//       if(a==-1){
//         cout<<getmedian(min_heap,max_heap)<<endl;
//         rebalance(min_heap,max_heap);
//       }
//       else{
//         insertNumber(a,min_heap,max_heap);
//         rebalance(min_heap,max_heap);
//       }
//       cin>>a;
//     }
//   }
//   return 0;
// }


#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int main(int argc, const char * argv[])
{
    ll t;
    scanf(" %lld", &t);

    for (ll i = 0; i < t; i++)
    {
        priority_queue<ll> max_heap;
        priority_queue <ll, vector<ll>, greater<ll> > min_heap;
        ll inp;
        scanf(" %lld", &inp);

        max_heap.push(inp);

        ll n;
        scanf(" %lld", &n);

        while (n != 0)
        {
            ll length_max_heap = max_heap.size();
            ll length_min_heap = min_heap.size();
            ll median;

            if (length_max_heap > length_min_heap)
                median = max_heap.top();
            else if (length_max_heap < length_min_heap)
                median = min_heap.top();
            else
                if (length_max_heap == 0 and length_min_heap == 0)
                {
                    max_heap.push(n);
                    scanf(" %lld", &n);
                    continue;
                }
                else
                    median = min(max_heap.top(), min_heap.top());

            if (n == -1)
            {
                printf("%lld\n", median);

                if (length_max_heap == 0)
                    min_heap.pop();
                else if (length_min_heap == 0)
                    max_heap.pop();
                else if (max_heap.top() == median)
                    max_heap.pop();
                else
                    min_heap.pop();
                scanf(" %lld", &n);
                continue;
            }


            if (n >= median)
            {
                if (length_max_heap >= length_min_heap)
                    min_heap.push(n);
                else if (length_max_heap < length_min_heap)
                {
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                    min_heap.push(n);
                }
            }

            else
            {
                if (length_max_heap <= length_min_heap)
                    max_heap.push(n);
                else if (length_max_heap > length_min_heap)
                {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(n);
                }
            }

            scanf(" %lld", &n);
        }
    }
}
