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
#define pln(x) printf("%lldn",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12fn",x)
#define pnl() printf("n")
#define fs first
#define sc second
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
const int INF = 2000000000;
typedef pair<int,int> PII;

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
//while((getchar())!='n'); //buffer clear
ll gcd(ll a,ll b)
{    ll r;
    while(b)
    {    r= a%b;a = b; b = r;
    }
    return a;
}
int Dp[35][2];
int main()
{

    rep(i,35)
    {
        Dp[i][0]=MOD;
        Dp[i][1]=-1;
    }
    Dp[0][0]=0;
    Dp[0][1]=0;

    Dp[1][0] = 2;
    Dp[1][1] = 2;
    forup(i,2,35)
    {
        int totwire =i+1;
        for(int j=1;j<=i;j++)
        {  // pis(j);
            //pis(j-1);
            //pin(i-j);
            Dp[i][0]= min(Dp[i][0],totwire+Dp[j-1][0]+Dp[i-j][0]);
            Dp[i][1]= max(Dp[i][1],totwire+Dp[j-1][1]+Dp[i-j][1]);
        }
        //cout<<i<<" "<<Dp[i][0]<<Dp[i][1]<<endl;
    }

    int t;
    gi(t);
    while(t--)
    {
        int n,k;
        gi(n);
        gi(k);
        //pis(Dp[n][0]);
        //pis(Dp[n][1]);

        if(k<Dp[n][0])
            pin(-1);
        else if(k>Dp[n][1])
            pin(k-Dp[n][1]);
        else
            pin(0);
    }
}
