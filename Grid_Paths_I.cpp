#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define sz size()
long double pi=acos(-1);
vector<bool> primes(1e6+1,true);
vector<ll>pr;
void seive() {
    primes[1]=false;
    for(int i=2; i*i<=(1e9); i++) {
        if(primes[i]) {
            for(int j=i*i; j<=(1e6); j+=i) {
                primes[j]=false;
            }
            pr.pb(i);
        }
        
    }
}
ll mod=1e9+7;
 
void solve() {
    ll n,m,d1,d2,k,q,mx=LLONG_MIN,mn=LLONG_MAX;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
    ll f=0,x=0;

    for(int i=0;i<n;i++){
        if(x==0 && s[i][0]=='.'){
            dp[i+1][1]=1;
        }
        else{
            x=1;
        }

        if(f==0 && s[0][i]=='.'){
            dp[1][i+1]=1;
        }
        else{
            f=1;
        }

    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(s[i][j]=='.'){
            dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1];
            dp[i+1][j+1]%=mod;
            }
        }
    }
    //    for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
          
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][n]<<endl;
 





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