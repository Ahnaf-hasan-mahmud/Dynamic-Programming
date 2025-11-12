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
           //spf[i]=i          
            for(ll j=i*i; j<=(val+1); j+=i) {
                primes[j]=false;
                //spf[j]=min(spf[j],(ll)i);  
                
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
    string a,b;
    cin>>a>>b;
    n=a.size();
    m=b.size();
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;

            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
   // cout<<dp[n][m]<<endl;

    ll l=n;
    ll r=m;
    string ans;
    while(l>0 && r>0){
        if(a[l-1]==b[r-1]){
            ans.pb(a[l-1]);
            l--;
            r--;
        }
        else if(dp[l-1][r]>dp[l][r-1]){
            l--;
        }
        else{
            r--;
        }
       // cout<<ans<<" ";
    }
    reverse(all(ans));

    cout<<ans<<endl;

    




}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
   // seive();
    // chk();
  //    cin>>t;
    ll cs=0;
    while(t--) {        //cout<<"Case "<<++cs<<": ";
        solve();
    }
}