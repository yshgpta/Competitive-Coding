//ysh_gpta
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll gcd( ll a, ll b ){
    if(b==0){
         return a;
    }
    else{
         return gcd( b, a%b );
    }
}

vi parent(20005);
vi size(200005,0);
int findParent(int u){
    if(u!=parent[u])
    parent[u]=findParent(parent[u]);
    return parent[u];
}
void unin(int u,int v){
    if(size[u]>size[v]){
        parent[v] = findParent(u);
        size[parent[u]] += size[v];
    }else{
        parent[u] = findParent(v);
        size[parent[v]] += size[u];
    }
}

int main(){
    FastIO
    int t;
    cin>>t;
    while(t--){
        parent.clear();
        int n;
        cin>>n;
        vpii arr(n+1);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            arr[i].ff = u;
            arr[i].ss = v;
        }
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        
        int q;
        cin>>q;
        stack<int> st;
        map<int,int> mp;
        while(q--){
            char ch;
            cin>>ch;
            if(ch=='Q')
            st.push(-1);
            else{
                int a;
                cin>>a;
                st.push(a);
                mp[a]=1;
            }
        }
        int count = n*(n-1)/2;
        for(int i=1;i<n;i++){
            if(mp.find(i)==mp.end()){
                int u = findParent(arr[i].ff);
                int v = findParent(arr[i].ss);
                if(u!=v){
                    count -= size[u]*size[v];
                    unin(u,v);
                }
                
            }
        }
        // for(int i=1;i<=n;i++)
        // parent[i] = findParent(i);
        // for(int i=1;i<=n;i++)
        // cout<<parent[i]<<" ";
        // cout<<endl;
        // map<int,int> hmp;
        // for(int i=1;i<=n;i++){
        //     if(hmp.find(parent[i])==hmp.end())
        //     hmp[parent[i]]=1;
        //     else
        //     hmp[parent[i]]++;
        // }
        // for(auto it=hmp.begin();it!=hmp.end();it++)
        // if(it->ss>1)
        // count -= it->ss * (it->ss-1)/2;

        
        stack<int> ans; 
        while(!st.empty()){
            int tp = st.top();
            st.pop();
            if(tp==-1)
            ans.push(count);
            else{
                int u = findParent(arr[tp].ff);
                int v = findParent(arr[tp].ss);
                if(u!=v){
                    count -= size[u]*size[v];
                    unin(u,v);
                }
            }
        }
        while(!ans.empty()){
            int tp = ans.top();
            ans.pop();
            cout<<tp<<endl;
        }
    }
    return 0;
}