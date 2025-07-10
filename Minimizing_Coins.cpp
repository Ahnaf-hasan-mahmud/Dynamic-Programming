#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define sz size()
long double pi=acos(-1);
vector<bool> primes(100000+1,true);
void seive() {
    primes[1]=false;
    for(int i=2; i*i<=100000; i++) {
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
    ll x=1e10;
    vector<ll>a(n+1),dp(1e6+1,1e18);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1; i<=n; i++) {
        dp[a[i]]=1;
 
    }
    for(int j=a[1]; j<=m; j++) {
        for(int i=1; i<=n; i++) {
            if(j>=a[i] && (dp[j-a[i]]+dp[a[i]])>0) {
                dp[j]=min({dp[j],dp[a[i]]+dp[j-a[i]],(ll)1e18});
            }
        }
       // cout<<dp[j]<<" "<<j<<" ";
    }
    if(dp[m]>=(ll)(1e18)) {
        cout<<-1<<endl;
        return;
    }
    cout<<dp[m]<<endl;
 
 
 
 
 
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // seive();
    // chk();
    // cin>>t;
    ll cs=0;
    while(t--) {        //cout<<"Case "<<++cs<<": ";
        solve();
    }
}