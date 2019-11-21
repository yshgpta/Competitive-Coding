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

struct TrieNode{
    struct TrieNode* children[26];
    int freq;
    bool isleaf;
};
TrieNode* createNode(){
    TrieNode* trie = new TrieNode;
    for(int i=0;i<26;i++)
    trie->children[i] = NULL;
    trie->isleaf = false;
    trie->freq = 1;
    return trie;
}
void insert(TrieNode* root,string key){
    TrieNode* temp = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(!temp->children[index])
        temp->children[index] = createNode();
        else
        temp->children[index]->freq++;
        cout<<key[i]<<temp->freq<<endl;
        temp = temp->children[index];
    }
    cout<<"hello"<<endl;
    temp->isleaf=true;
}
string search(TrieNode* root,string key){
    TrieNode* temp = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        temp=temp->children[index];
        cout<<temp->freq<<key[i]<<endl;
        if(temp->freq==1){
            return key.substr(0,i+1);
        }
    }
}

vector<string> pre(vector<string> &A) {
    TrieNode* root = createNode();
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }
    vector<string> v;
    for(int i=0;i<A.size();i++){
        v.push_back(search(root,A[i]));
    }
    return v;
}


int main(){
   FastIO
   
   return 0;
}
