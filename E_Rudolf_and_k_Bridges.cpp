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
    cin>>n>>m>>k>>d1;
    vector<ll>a[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x;
            cin>>x;
            a[i].pb(x);
        }
    }
    vector<vector<ll>>dp(n,vector<ll>(m));
    d1++;
    for(int i=0;i<n;i++){
        dp[i][0]=1;
        deque<ll>dq;
        dq.pb(0);
        for(int j=1;j<m;j++){
            while(!dq.empty() && dq.front()<j-d1) dq.pop_front();

            ll x=dq.front();
            dp[i][j]=dp[i][x]+a[i][j]+1;

            while(!dq.empty() && dp[i][dq.back()]>=dp[i][j]){
                dq.pop_back();
            }
            dq.pb(j);

        }

    }

    vector<ll>ans;
    for(int i=0;i<n;i++){
        ans.pb(dp[i][m-1]);
    }
    ll sum=0;
    for(int i=0;i<k;i++){
        sum+=ans[i];
    }
    mx=sum;
    ll i=0;
    ll j=k-1;
    while(j<n){
        i++;
        j++;
        if(j==n){
            break;
        }
        sum+=ans[j];
        sum-=ans[i-1];
        mx=min(mx,sum);

    }
    cout<<mx<<endl;



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