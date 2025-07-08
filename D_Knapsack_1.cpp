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
    for(int i=2; i*i<=100000;i++) {
        if(primes[i]) {
            for(int j=i*i; j<=100000; j+=i) {
                primes[j]=false;
            }
        }
    }
}
ll mod=1e9+7;
ll N=1e6;

void solve() {
    ll n,m,d1,d2,k,q,mx=LLONG_MIN,mn=LLONG_MAX;
    cin>>n>>m;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    vector<pair<ll,ll>>a(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i].second<=j){
             dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].second]+a[i].first);
             //cout<<dp[i][j]<<" ";
            }
        }
    }
    cout<<dp[n][m]<<endl;
    




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