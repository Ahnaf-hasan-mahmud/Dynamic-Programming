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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>dp(m+1,0);
    sort(a.begin(),a.end());

    dp[0]=1;
    for(int i=a[0];i<=m;i++){
        for(int j=0;j<n;j++){
            if((i-a[j])>=0){
                dp[i]+=dp[i-a[j]];
                if(dp[i]>=mod){
                    dp[i]-=mod;
                }
            }

        }
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