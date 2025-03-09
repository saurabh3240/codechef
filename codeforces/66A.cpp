
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
ll dp1[10000005];
ll dp2[10000005];
int main()
{
    string s;
    cin>>s;
    int n= s.size();
    if(n<3)
    {
        cout<<"byte";
    }
    else if(n==3)
    {
        if(s.compare("127")<=0)
            cout<<"byte";
        else
            cout<<"short";
    }
    else if(n<5)
    {
        cout<<"short";

    }
    else if(n==5)
    {
        if(s.compare("32767")<=0)
            cout<<"short";
        else
            cout<<"int";
    }
    else if(n<10)
    {
        cout<<"int";
    }
    else if(n==10)
    {
        if(s.compare("2147483647")<=0)
            cout<<"int";
        else
            cout<<"long";
    }
    else if(n<19)
    {
        cout<<"long";
    }
    else if(n==19)
    {    if(s.compare("9223372036854775807")<=0)
            cout<<"long";
        else
            cout<<"BigInteger";
    }
    else
        cout<<"BigInteger";
}
