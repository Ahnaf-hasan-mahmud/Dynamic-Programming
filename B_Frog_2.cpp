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
    cin>>n>>k;
    vector<ll>a(n+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    vector<ll>dp(n+1);
    a[0]=a[1];
    dp[0]=0;
    dp[1]=0;
    dp[2]=abs(a[2]-a[1]);
    for(ll i=3; i<=n; i++) {
        dp[i]=dp[i-1]+abs(a[i]-a[i-1]);
        for(int j=1; j<=min(k,i); j++) {
            dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);
        }
    }
    cout<<dp[n]<<endl;


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