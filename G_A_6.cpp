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

ll const val=sqrtl(1e15);

vector<bool> primes(val+1,true);
//vector<ll>spf(1e7+1,0);
vector<ll>pr;
void seive() {
    primes[0]=primes[1]=false;
    for(ll i=2; i*i<=(val+1); i++) {
        if(primes[i]) {
            for(ll j=i*i; j<=(val+1); j+=i) {
                primes[j]=false;
                
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
    cin>>n;
    vector<ll>a[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            ll x;
            cin>>x;
            a[i].pb(x);
        }
    }

    vector<vector<ll>>dp(n,vector<ll>(3));
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];

    for(int i=1;i<n;i++){
        dp[i][0]=max(a[i][0]+max(dp[i-1][1],dp[i-1][2]),dp[i-1][0]);
        
        dp[i][1]=max(a[i][1]+max(dp[i-1][0],dp[i-1][2]),dp[i-1][1]);

        dp[i][2]=max(a[i][2]+max(dp[i-1][1],dp[i-1][0]),dp[i-1][2]);

    }

    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;





}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
   // seive();
    // chk();
    //  cin>>t;
    ll cs=0;
    while(t--) {        //cout<<"Case "<<++cs<<": ";
        solve();
    }
}