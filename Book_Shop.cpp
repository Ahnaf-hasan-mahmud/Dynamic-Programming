#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define sz size()
long double pi=acos(-1);
vector<bool> primes((ll)1e9,true);
void seive() {
    primes[1]=false;
    for(int i=2; i*i<=1e9; i++) {
        if(primes[i]) {
            for(int j=i*i; j<=100000; j+=i) {
                primes[j]=false;
            }
        }
    }
}
ll mod=1e9+7;
 
void solve() {
    ll n,m,d1,d2,k,q,mx=LLONG_MIN,mn=LLONG_MAX;
    cin>>n>>m;
    vector<pair<ll,ll>>a(n+1),b(n+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i].first;
    }
    for(int i=1; i<=n; i++) {
        cin>>a[i].second;
    }
 
    vector<ll>dp(m+1,0);
 
    for(int i=1; i<=n; i++) {
        for(int j=m; j>=a[i].first; j--) {
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
        }
    }
    cout<<dp[m]<<endl;
 
 
 
 
 
 
 
 
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //seive();
    // chk();
    // cin>>t;
    ll cs=0;
    while(t--) {        //cout<<"Case "<<++cs<<": ";
        solve();
    }
}