#include<bits/stdc++.h>
using namespace std;

typedef long long              ll;
#define endl                   '\n'
#define pb                     push_back
#define F                      first
#define S                      second
#define sz                     size()
#define yes                    cout << "Yes\n";
#define no                     cout << "No\n";
#define all(a)                 a.begin(), a.end()
#define rall(a)                a.rbegin(), a.rend()

long double pi=acos(-1);

ll const val=2e5;

vector<bool> primes(val+1,true);
vector<ll>spf(val+1,0);
vector<ll>pr;
void seive() {
    primes[0]=primes[1]=false;
    for(ll i=2; i*i<=(val+1); i++) {
        if(primes[i]) {
            spf[i]=i;
            for(ll j=i*i; j<=(val+1); j+=i) {
                primes[j]=false;
                spf[j]=i;
            }
        }

    }
    for(ll i=1; i<=(val+1); i++) {
        if(primes[i]) {
            pr.pb(i);
        }
    }
}


ll mod=1e9+7;


void solve() {
    ll n,m,d1,d2,k,q,mx=LLONG_MIN,mn=LLONG_MAX;
    cin>>n>>m;
    vector<ll>a[n];
    ll tot=0;
    for(int i=0; i<m; i++) {
        cin>>k;
        mn=1e17;
        for(int j=0; j<k; j++) {
            ll x;
            cin>>x;
            a[i].pb(x);
            mn=min(mn,x);

        }
        tot+=mn;
    }

    if(tot>n) {
        cout<<"no solution"<<endl;
        return;
    }
    vector<ll>dp(n+1,0),nxdp(n+1,0);
    dp[0]=1;

    for(int i=0; i<m; i++) {
        fill(all(nxdp),0);
        for(int j=0; j<=n; j++) {
            if(!dp[j]) continue;

            for(auto x : a[i]) {
                ll cost=x+j;
                if(cost<=n) {
                    nxdp[cost]=1;
                }
            }
        }
        dp.swap(nxdp);
    }
    for(int i=n; i>=0; i--) {

        if(dp[i]) {
            cout<<i<<endl;
            return;
        }
    }
    cout<<"no solution"<<endl;



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // seive();
    // chk();
    cin>>t;
    ll cs=0;
    while(t--) {        //cout<<"Case "<<++cs<<": ";
        solve();
    }
}