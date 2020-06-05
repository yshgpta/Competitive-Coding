//ysh_gpta
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
typedef long long ll;
#define vb vector<bool>
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll,ll>
#define vpii vector<pair<ll,ll> >
#define mkp make_pair
#define pb push_back
#define INF 1000000000000000
#define MOD 1000000007
#define ff first
#define ss second
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//ll gcd( ll a, ll b ){if(b==0) return a; else return gcd( b, a%b );}
//ll ncr(ll n,ll r){ll ans=1;r=min(r,n-r);for (int i=1;i<=r;i++){ans*=(n-r+i);ans/=i;}return ans;}
//void printArray(vi &v){for(int i=0;i<v.size();i++) cout<<v[i]<<endl; cout<<endl; }

vb vis(205,false);
ll n,m,k;

void check(ll cx,ll cy,vpii &s, vpii &e,ll p){
    for(int i=p;i<k;i++){
        ll sx = s[i].ff + cx;
        ll sy = s[i].ss + cy;
        if(s[i].ff + cx<1)
        sx=1;
        else if(s[i].ff + cx>n)
        sx = n;
        if(s[i].ss + cy < 1)
        sy =1;
        else if(s[i].ss + cy > m)
        sy = m;
        if((sx== e[i].ff) && (sy == e[i].ss)){
            vis[i] = true;
        }
    }
    return;
}

int main(){
   FastIO
   cin>>n>>m>>k;
   vpii s(k),e(k);
   for(int i=0;i<k;i++)
   cin>>s[i].ff>>s[i].ss;
   for(int i=0;i<k;i++)
   cin>>e[i].ff>>e[i].ss;
   ll cx=0,cy=0;
   string str;
   for(int i=0;i<k;i++){
       if(vis[i]){
           continue;
       }
       ll curr_x = s[i].ff + cx;
       ll curr_y = s[i].ss + cy;
       ll diffx = e[i].ff - curr_x;
       ll diffy = e[i].ss - curr_y;
       if(diffx>0){
           while(curr_x < e[i].ff){
               curr_x++;
               cx++;
               str += 'D';
               check(cx,cy,s,e,i+1);
           }
       }else if(diffx<0){
           while(curr_x > e[i].ff){
               curr_x--;
               cx--;
               str+='U';
               check(cx,cy,s,e,i+1);
           }
       }
       if(diffy<0){
           while(curr_y > e[i].ss){
               curr_y--;
               cy--;
               str+='L';
               check(cx,cy,s,e,i+1);
           }
       }
       else if(diffy>0){
           while(curr_y < e[i].ss){
               curr_y++;
               cy++;
               str+='R';
               check(cx,cy,s,e,i+1);
           }
       }
       vis[i] = true;
   }
   cout<<str.length()<<endl;
   cout<<str;

   return 0;
}