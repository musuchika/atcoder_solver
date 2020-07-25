#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;
using vpii=vector<pair<int,int>>;
using plli=pair<ll,int>;
using vplli=vector<pair<ll,int>>;
using pllll=pair<ll,ll>;
using vpllll=vector<pair<ll,ll>>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i-1; i >= (ll)end_i; i--)

long long INF = 1LL<<60;
// digit,cnt1,inc1
ll dp[12][12][2];
int main(){
    string S;
    cin>>S;
    int n=S.size();
    dp[0][0][1]=1;
    rep(i,0,n){
        int v=S[i]-'0';
        rep(same,0,2){
            rep(cnt1,0,10){
                rep(d,0,10){
                    int ni=i+1,nsame=same,ncnt1=cnt1;
                    if(same){
                        if(d>v)break;
                        else if(d<v)nsame=0;
                    }
                    if(d==1)ncnt1++;
                    dp[ni][ncnt1][nsame]+=dp[i][cnt1][same];
                }
            }
        }
    }
    int ans=0;
    rep(cnt,1,n+1){
        rep(same,0,2)
            ans+=dp[n][cnt][same]*cnt;
    }
    cout<<ans<<endl;
    return 0;
}
