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
    cin>>n;
    vector<ll>dp(n+1,0);
    for(int i=1; i<=n; i++) {
        string s=to_string(i);
        mx=-1;
        for(int j=0; j<s.size(); j++) {
            mx=max((ll)(s[j]-'0'),mx);
        }
        dp[i]=dp[i-mx]+1;
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