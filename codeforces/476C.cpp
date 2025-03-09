#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
#define INF 1000000000
#define ull unsigned long long

using namespace std;
ll mod_pow(ll num, ll pow, ll mod)
{
    ll test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
int main()
{

	ll a,b;
    cin>>a>>b;

    if(b==1)
        pln(0ll);
    else
    {
        ll n = a;
        ll st = b+1;
        ll d = b;
        ll ans = (2*st)%MOD+((n-1)*d)%MOD;
        // pls(n);
        // pls(st);
        // pls(d);
        // pls(ans);
        ans%=MOD;
        ans*=n;
        ans%=MOD;
        ans*=mod_pow(2,MOD-2,MOD);
        ans%=MOD;
    //    pln(ans);
//        cout<<ans<<endl;
        ll st2 = b-1;


        ll x = st2*(st2+1);
        x%=MOD;
        x*=mod_pow(2,MOD-2,MOD);
        x%=MOD;
    //    pln(x);

//        cout<<x<<endl;
        ans*=x;
        ans%=MOD;
        cout<<ans<<endl;
    }
}
