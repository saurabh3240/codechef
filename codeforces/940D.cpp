
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
#include<unordered_map>
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
ull mod_pow(ull num, ull pow, ull mod)
{
    ull test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
//while((getchar())!='\n'); //buffer clear
ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;a = b; b = r;
	}
	return a;
}
int a[100005];
int cum[100005];
int main()
{
    int n;
    gi(n);
    rep(i,n)
    {    gi(a[i]);
    }
    // cum[i+1]= cum[i]+arr[i+1];
    string b;

    cin>>b;
    ll l =-MOD+7,r=MOD-7;
    forup(i,4,n)
    {
        if(b[i]==b[i-1])
        {

        }
        else if(b[i]=='0'&&b[i-1]=='1'&&b[i-2]=='1'&&b[i-3]=='1'&&b[i-4]=='1')
        {
            ll nr = MOD-7;
            rep(j,5)
                nr = min(nr,(ll)a[i-j]);
            if(r>nr)
                r = nr-1;
        }
        else if(b[i]=='1'&&b[i-1]=='0'&&b[i-2]=='0'&&b[i-3]=='0'&&b[i-4]=='0')
        {
            ll nl = -MOD+7;
            rep(j,5)
                nl = max(nl,(ll)a[i-j]);
            if(l<nl)
                l = nl+1;
        }

    }
    cout<<l<<" "<<r;

}
