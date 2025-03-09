
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
ll n,k,A,B;
map<ll,int> mp;


// ll call(int x)
// {
//     if(x==1)
//         return 0;
//     if(mp[x]!=0)
//     {
//         return mp[x];
//     }
//     else
//     {
//         if(x%k==0)
//         {
//             ll z = min(B+call(x/k),A+call(x-1));
//             mp[x]=z;
//             return z;
//         }
//         else
//         {
//             ll z =  call(x-1)+A;
//             mp[x]=z;
//             return z;
//         }
//     }
// }
int main()
{
    cin>>n>>k>>A>>B;
    if(k==1)
    {
        cout<<(n-1)*A<<endl;
        return 0;
    }
        ll ans =0;
        ll x =n;
        while(x>1)
        {

            if(x%k==0)
            {
                ll y = x/k;
                ans+=min(B,(x-y)*A);
                x = x/k;

            }
            else
            {
                ll z = x%k;
                ans+=z*A;
                x = x-z;
                if(x==0)
                {
                    x=1;
                    ans-=A;
                }
            }

        }
        cout<<ans<<endl;



}
