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
ll c=-1;
ll k;
string s;
vi bad(26);
struct TrieNode{
    struct TrieNode* children[26];
};
TrieNode* createNode(){
    TrieNode* trie = new TrieNode;
    for(int i=0;i<26;i++)
    trie->children[i] = NULL;
    return trie;
}
void insert(TrieNode* root,string key){
    TrieNode* temp = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(!temp->children[index])
        temp->children[index] = createNode();
        temp = temp->children[index];
    }
}

void search(TrieNode* root,ll cnt){
    if(root==NULL)
    return;
    if(cnt>k)
    return;
    c++;
    for(int i=0;i<26;i++){
        if(root->children[i]==NULL)
        continue;
        search(root->children[i],cnt+1-bad[i]);
    }
}

int main(){
   FastIO
   string str;
   cin>>str;
   cin>>s;
   cin>>k;
   for(int i=0;i<26;i++){
       bad[i]=s[i]-'0';
   }
   TrieNode *root = createNode();
   ll n = str.length();
   for(int i=0;i<n;i++){
       insert(root,str.substr(i,n-i));
   }
   search(root,0);
   cout<<c;
   return 0;
}